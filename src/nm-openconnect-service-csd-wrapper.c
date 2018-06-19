/* NetworkManager-openconnect -- OpenConnect VPN plugin
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Copyright © 2018 Red Hat, Inc.
 */

#include "nm-default.h"

#include <stdlib.h>

#include "nm-openconnect-csd-service-dbus.h"

int
main (int argc, char *argv[])
{
	NMDBusOpenconnectCsd *proxy;
	GError *error = NULL;
	const char *bus_path;
	const gchar *arguments[argc + 1];
	gchar *output = NULL;
	gint return_code = 0;
	int i;

	for (i = 0; i < argc; i++)
		arguments[i] = argv[i];
	arguments[i] = NULL;

	bus_path = getenv ("NM_DBUS_SERVICE_OPENCONNECT");
	if (!bus_path)
		bus_path = NM_DBUS_SERVICE_OPENCONNECT;

	proxy = nmdbus_openconnect_csd_proxy_new_for_bus_sync (G_BUS_TYPE_SYSTEM,
	                                                       G_DBUS_PROXY_FLAGS_NONE,
	                                                       bus_path,
	                                                       NM_DBUS_PATH_OPENCONNECT_CSD,
	                                                       NULL,
	                                                       &error);
	if (proxy == NULL) {
		g_printerr ("Failed to create a VPN service bus proxy: %s\n", error->message);
		g_error_free (error);
		return EXIT_FAILURE;
	}

	if (!nmdbus_openconnect_csd_call_run_sync (proxy, arguments, &output, &return_code, NULL, &error)) {

		g_printerr ("Failed to forward the CSD run to the VPN service: %s\n", error->message);
		g_error_free (error);
		g_object_unref (proxy);
		return EXIT_FAILURE;
	}

	g_print ("%s", output);
	g_free (output);
	g_object_unref (proxy);

	return return_code;
}
