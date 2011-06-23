
/*
 * WPA Supplicant / dbus-based control interface for p2p
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#ifndef DBUS_NEW_HANDLERS_P2P_H
#define DBUS_NEW_HANDLERS_P2P_H

struct peer_handler_args {
	struct wpa_supplicant *wpa_s;
	u8 p2p_device_addr[ETH_ALEN];
};

struct groupmember_handler_args {
	struct wpa_supplicant *wpa_s;
	u8 member_addr[ETH_ALEN];
};

/*
 * P2P Device methods
 */

DBusMessage *wpas_dbus_handler_p2p_find(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_stop_find(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_rejectpeer(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_listen(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_extendedlisten(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_presence_request(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_prov_disc_req(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_group_add(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_connect(
		DBusMessage *message,
		struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_invite(
		DBusMessage *message,
		struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_disconnect(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_flush(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_add_service(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_delete_service(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_flush_service(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_service_sd_req(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_service_sd_res(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_service_sd_cancel_req(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_service_update(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_handler_p2p_serv_disc_external(
	DBusMessage *message, struct wpa_supplicant *wpa_s);

/*
 * P2P Device property accessor methods.
 */
DBusMessage *wpas_dbus_setter_p2p_device_properties(DBusMessage *message,
				      struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_getter_p2p_device_properties(DBusMessage *message,
				      struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_getter_p2p_peers(DBusMessage *message,
					  struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_getter_p2p_role(DBusMessage *message,
					  struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_getter_p2p_group(DBusMessage *message,
					  struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_getter_p2p_peergo(DBusMessage *message,
					  struct wpa_supplicant *wpa_s);

/*
 * P2P Peer properties.
 */
DBusMessage *wpas_dbus_getter_p2p_peer_properties(
		DBusMessage *message,
		struct peer_handler_args *peer);

DBusMessage *wpas_dbus_getter_p2p_peer_ies(
		DBusMessage *message,
		struct peer_handler_args *peer);

/*
 * P2P Group properties
 */

DBusMessage *wpas_dbus_getter_p2p_group_members(
		DBusMessage *message,
		struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_getter_p2p_group_properties(
		DBusMessage *message,
		struct wpa_supplicant *wpa_s);

DBusMessage *wpas_dbus_setter_p2p_group_properties(
		DBusMessage *message,
		struct wpa_supplicant *wpa_s);

/*
 * P2P Persistent Group properties
 */

DBusMessage * wpas_dbus_getter_persistent_groups(DBusMessage *message,
						 struct wpa_supplicant *wpa_s);
DBusMessage * wpas_dbus_getter_persistent_group_properties(
	DBusMessage *message, struct network_handler_args *net);

#endif /* DBUS_NEW_HANDLERS_P2P_H */
