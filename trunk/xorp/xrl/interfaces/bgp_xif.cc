/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/bgp_xif.cc,v 1.22 2004/03/24 19:34:31 atanu Exp $"

#include "bgp_xif.hh"

bool
XrlBgpV0p2Client::send_get_bgp_version(
	const char*	the_tgt,
	const GetBgpVersionCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_bgp_version");
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_bgp_version, cb));
}


/* Unmarshall get_bgp_version */
void
XrlBgpV0p2Client::unmarshall_get_bgp_version(
	const XrlError&	e,
	XrlArgs*	a,
	GetBgpVersionCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t version;
    try {
	a->get("version", version);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &version);
}

bool
XrlBgpV0p2Client::send_local_config(
	const char*	the_tgt,
	const uint32_t&	as,
	const IPv4&	id,
	const LocalConfigCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/local_config");
    x.args().add("as", as);
    x.args().add("id", id);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_local_config, cb));
}


/* Unmarshall local_config */
void
XrlBgpV0p2Client::unmarshall_local_config(
	const XrlError&	e,
	XrlArgs*	a,
	LocalConfigCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_set_local_as(
	const char*	the_tgt,
	const uint32_t&	as,
	const SetLocalAsCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/set_local_as");
    x.args().add("as", as);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_set_local_as, cb));
}


/* Unmarshall set_local_as */
void
XrlBgpV0p2Client::unmarshall_set_local_as(
	const XrlError&	e,
	XrlArgs*	a,
	SetLocalAsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_get_local_as(
	const char*	the_tgt,
	const GetLocalAsCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_local_as");
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_local_as, cb));
}


/* Unmarshall get_local_as */
void
XrlBgpV0p2Client::unmarshall_get_local_as(
	const XrlError&	e,
	XrlArgs*	a,
	GetLocalAsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t as;
    try {
	a->get("as", as);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &as);
}

bool
XrlBgpV0p2Client::send_set_bgp_id(
	const char*	the_tgt,
	const IPv4&	id,
	const SetBgpIdCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/set_bgp_id");
    x.args().add("id", id);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_set_bgp_id, cb));
}


/* Unmarshall set_bgp_id */
void
XrlBgpV0p2Client::unmarshall_set_bgp_id(
	const XrlError&	e,
	XrlArgs*	a,
	SetBgpIdCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_get_bgp_id(
	const char*	the_tgt,
	const GetBgpIdCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_bgp_id");
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_bgp_id, cb));
}


/* Unmarshall get_bgp_id */
void
XrlBgpV0p2Client::unmarshall_get_bgp_id(
	const XrlError&	e,
	XrlArgs*	a,
	GetBgpIdCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    IPv4 id;
    try {
	a->get("id", id);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &id);
}

bool
XrlBgpV0p2Client::send_add_peer(
	const char*	the_tgt,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const uint32_t&	as,
	const IPv4&	next_hop,
	const uint32_t&	holdtime,
	const AddPeerCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/add_peer");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    x.args().add("as", as);
    x.args().add("next_hop", next_hop);
    x.args().add("holdtime", holdtime);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_add_peer, cb));
}


/* Unmarshall add_peer */
void
XrlBgpV0p2Client::unmarshall_add_peer(
	const XrlError&	e,
	XrlArgs*	a,
	AddPeerCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_delete_peer(
	const char*	the_tgt,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const DeletePeerCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/delete_peer");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_delete_peer, cb));
}


/* Unmarshall delete_peer */
void
XrlBgpV0p2Client::unmarshall_delete_peer(
	const XrlError&	e,
	XrlArgs*	a,
	DeletePeerCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_enable_peer(
	const char*	the_tgt,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const EnablePeerCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/enable_peer");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_enable_peer, cb));
}


/* Unmarshall enable_peer */
void
XrlBgpV0p2Client::unmarshall_enable_peer(
	const XrlError&	e,
	XrlArgs*	a,
	EnablePeerCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_disable_peer(
	const char*	the_tgt,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const DisablePeerCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/disable_peer");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_disable_peer, cb));
}


/* Unmarshall disable_peer */
void
XrlBgpV0p2Client::unmarshall_disable_peer(
	const XrlError&	e,
	XrlArgs*	a,
	DisablePeerCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_set_peer_state(
	const char*	the_tgt,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const bool&	toggle,
	const SetPeerStateCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/set_peer_state");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    x.args().add("toggle", toggle);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_set_peer_state, cb));
}


/* Unmarshall set_peer_state */
void
XrlBgpV0p2Client::unmarshall_set_peer_state(
	const XrlError&	e,
	XrlArgs*	a,
	SetPeerStateCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_activate(
	const char*	the_tgt,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const ActivateCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/activate");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_activate, cb));
}


/* Unmarshall activate */
void
XrlBgpV0p2Client::unmarshall_activate(
	const XrlError&	e,
	XrlArgs*	a,
	ActivateCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_set_parameter(
	const char*	the_tgt,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const string&	parameter,
	const SetParameterCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/set_parameter");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    x.args().add("parameter", parameter);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_set_parameter, cb));
}


/* Unmarshall set_parameter */
void
XrlBgpV0p2Client::unmarshall_set_parameter(
	const XrlError&	e,
	XrlArgs*	a,
	SetParameterCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_next_hop_rewrite_filter(
	const char*	the_tgt,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const IPv4&	next_hop,
	const NextHopRewriteFilterCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/next_hop_rewrite_filter");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    x.args().add("next_hop", next_hop);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_next_hop_rewrite_filter, cb));
}


/* Unmarshall next_hop_rewrite_filter */
void
XrlBgpV0p2Client::unmarshall_next_hop_rewrite_filter(
	const XrlError&	e,
	XrlArgs*	a,
	NextHopRewriteFilterCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_originate_route4(
	const char*	the_tgt,
	const IPv4Net&	nlri,
	const IPv4&	next_hop,
	const bool&	unicast,
	const bool&	multicast,
	const OriginateRoute4CB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/originate_route4");
    x.args().add("nlri", nlri);
    x.args().add("next_hop", next_hop);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_originate_route4, cb));
}


/* Unmarshall originate_route4 */
void
XrlBgpV0p2Client::unmarshall_originate_route4(
	const XrlError&	e,
	XrlArgs*	a,
	OriginateRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_originate_route6(
	const char*	the_tgt,
	const IPv6Net&	nlri,
	const IPv6&	next_hop,
	const bool&	unicast,
	const bool&	multicast,
	const OriginateRoute6CB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/originate_route6");
    x.args().add("nlri", nlri);
    x.args().add("next_hop", next_hop);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_originate_route6, cb));
}


/* Unmarshall originate_route6 */
void
XrlBgpV0p2Client::unmarshall_originate_route6(
	const XrlError&	e,
	XrlArgs*	a,
	OriginateRoute6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_withdraw_route4(
	const char*	the_tgt,
	const IPv4Net&	nlri,
	const bool&	unicast,
	const bool&	multicast,
	const WithdrawRoute4CB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/withdraw_route4");
    x.args().add("nlri", nlri);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_withdraw_route4, cb));
}


/* Unmarshall withdraw_route4 */
void
XrlBgpV0p2Client::unmarshall_withdraw_route4(
	const XrlError&	e,
	XrlArgs*	a,
	WithdrawRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_withdraw_route6(
	const char*	the_tgt,
	const IPv6Net&	nlri,
	const bool&	unicast,
	const bool&	multicast,
	const WithdrawRoute6CB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/withdraw_route6");
    x.args().add("nlri", nlri);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_withdraw_route6, cb));
}


/* Unmarshall withdraw_route6 */
void
XrlBgpV0p2Client::unmarshall_withdraw_route6(
	const XrlError&	e,
	XrlArgs*	a,
	WithdrawRoute6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_get_peer_list_start(
	const char*	the_tgt,
	const GetPeerListStartCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_peer_list_start");
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_peer_list_start, cb));
}


/* Unmarshall get_peer_list_start */
void
XrlBgpV0p2Client::unmarshall_get_peer_list_start(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerListStartCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != 2)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    uint32_t token;
    bool more;
    try {
	a->get("token", token);
	a->get("more", more);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &token, &more);
}

bool
XrlBgpV0p2Client::send_get_peer_list_next(
	const char*	the_tgt,
	const uint32_t&	token,
	const GetPeerListNextCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_peer_list_next");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_peer_list_next, cb));
}


/* Unmarshall get_peer_list_next */
void
XrlBgpV0p2Client::unmarshall_get_peer_list_next(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerListNextCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 5) {
	XLOG_ERROR("Wrong number of arguments (%u != 5)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0);
	return;
    }
    IPv4 local_ip;
    uint32_t local_port;
    IPv4 peer_ip;
    uint32_t peer_port;
    bool more;
    try {
	a->get("local_ip", local_ip);
	a->get("local_port", local_port);
	a->get("peer_ip", peer_ip);
	a->get("peer_port", peer_port);
	a->get("more", more);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &local_ip, &local_port, &peer_ip, &peer_port, &more);
}

bool
XrlBgpV0p2Client::send_get_peer_id(
	const char*	the_tgt,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerIdCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_peer_id");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_peer_id, cb));
}


/* Unmarshall get_peer_id */
void
XrlBgpV0p2Client::unmarshall_get_peer_id(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerIdCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    IPv4 peer_id;
    try {
	a->get("peer_id", peer_id);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &peer_id);
}

bool
XrlBgpV0p2Client::send_get_peer_status(
	const char*	the_tgt,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerStatusCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_peer_status");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_peer_status, cb));
}


/* Unmarshall get_peer_status */
void
XrlBgpV0p2Client::unmarshall_get_peer_status(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerStatusCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != 2)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    uint32_t peer_state;
    uint32_t admin_status;
    try {
	a->get("peer_state", peer_state);
	a->get("admin_status", admin_status);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &peer_state, &admin_status);
}

bool
XrlBgpV0p2Client::send_get_peer_negotiated_version(
	const char*	the_tgt,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerNegotiatedVersionCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_peer_negotiated_version");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_peer_negotiated_version, cb));
}


/* Unmarshall get_peer_negotiated_version */
void
XrlBgpV0p2Client::unmarshall_get_peer_negotiated_version(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerNegotiatedVersionCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    int32_t neg_version;
    try {
	a->get("neg_version", neg_version);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &neg_version);
}

bool
XrlBgpV0p2Client::send_get_peer_as(
	const char*	the_tgt,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerAsCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_peer_as");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_peer_as, cb));
}


/* Unmarshall get_peer_as */
void
XrlBgpV0p2Client::unmarshall_get_peer_as(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerAsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t peer_as;
    try {
	a->get("peer_as", peer_as);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &peer_as);
}

bool
XrlBgpV0p2Client::send_get_peer_msg_stats(
	const char*	the_tgt,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerMsgStatsCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_peer_msg_stats");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_peer_msg_stats, cb));
}


/* Unmarshall get_peer_msg_stats */
void
XrlBgpV0p2Client::unmarshall_get_peer_msg_stats(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerMsgStatsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 6) {
	XLOG_ERROR("Wrong number of arguments (%u != 6)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0);
	return;
    }
    uint32_t in_updates;
    uint32_t out_updates;
    uint32_t in_msgs;
    uint32_t out_msgs;
    uint32_t last_error;
    uint32_t in_update_elapsed;
    try {
	a->get("in_updates", in_updates);
	a->get("out_updates", out_updates);
	a->get("in_msgs", in_msgs);
	a->get("out_msgs", out_msgs);
	a->get("last_error", last_error);
	a->get("in_update_elapsed", in_update_elapsed);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &in_updates, &out_updates, &in_msgs, &out_msgs, &last_error, &in_update_elapsed);
}

bool
XrlBgpV0p2Client::send_get_peer_established_stats(
	const char*	the_tgt,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerEstablishedStatsCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_peer_established_stats");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_peer_established_stats, cb));
}


/* Unmarshall get_peer_established_stats */
void
XrlBgpV0p2Client::unmarshall_get_peer_established_stats(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerEstablishedStatsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != 2)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    uint32_t transitions;
    uint32_t established_time;
    try {
	a->get("transitions", transitions);
	a->get("established_time", established_time);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &transitions, &established_time);
}

bool
XrlBgpV0p2Client::send_get_peer_timer_config(
	const char*	the_tgt,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerTimerConfigCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_peer_timer_config");
    x.args().add("local_ip", local_ip);
    x.args().add("local_port", local_port);
    x.args().add("peer_ip", peer_ip);
    x.args().add("peer_port", peer_port);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_peer_timer_config, cb));
}


/* Unmarshall get_peer_timer_config */
void
XrlBgpV0p2Client::unmarshall_get_peer_timer_config(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerTimerConfigCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 7) {
	XLOG_ERROR("Wrong number of arguments (%u != 7)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    uint32_t retry_interval;
    uint32_t hold_time;
    uint32_t keep_alive;
    uint32_t hold_time_conf;
    uint32_t keep_alive_conf;
    uint32_t min_as_orgination_interval;
    uint32_t min_route_adv_interval;
    try {
	a->get("retry_interval", retry_interval);
	a->get("hold_time", hold_time);
	a->get("keep_alive", keep_alive);
	a->get("hold_time_conf", hold_time_conf);
	a->get("keep_alive_conf", keep_alive_conf);
	a->get("min_as_orgination_interval", min_as_orgination_interval);
	a->get("min_route_adv_interval", min_route_adv_interval);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &retry_interval, &hold_time, &keep_alive, &hold_time_conf, &keep_alive_conf, &min_as_orgination_interval, &min_route_adv_interval);
}

bool
XrlBgpV0p2Client::send_register_rib(
	const char*	the_tgt,
	const string&	name,
	const RegisterRibCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/register_rib");
    x.args().add("name", name);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_register_rib, cb));
}


/* Unmarshall register_rib */
void
XrlBgpV0p2Client::unmarshall_register_rib(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterRibCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpV0p2Client::send_get_v4_route_list_start(
	const char*	the_tgt,
	const GetV4RouteListStartCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_v4_route_list_start");
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_v4_route_list_start, cb));
}


/* Unmarshall get_v4_route_list_start */
void
XrlBgpV0p2Client::unmarshall_get_v4_route_list_start(
	const XrlError&	e,
	XrlArgs*	a,
	GetV4RouteListStartCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t token;
    try {
	a->get("token", token);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &token);
}

bool
XrlBgpV0p2Client::send_get_v6_route_list_start(
	const char*	the_tgt,
	const GetV6RouteListStartCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_v6_route_list_start");
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_v6_route_list_start, cb));
}


/* Unmarshall get_v6_route_list_start */
void
XrlBgpV0p2Client::unmarshall_get_v6_route_list_start(
	const XrlError&	e,
	XrlArgs*	a,
	GetV6RouteListStartCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t token;
    try {
	a->get("token", token);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &token);
}

bool
XrlBgpV0p2Client::send_get_v4_route_list_next(
	const char*	the_tgt,
	const uint32_t&	token,
	const GetV4RouteListNextCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_v4_route_list_next");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_v4_route_list_next, cb));
}


/* Unmarshall get_v4_route_list_next */
void
XrlBgpV0p2Client::unmarshall_get_v4_route_list_next(
	const XrlError&	e,
	XrlArgs*	a,
	GetV4RouteListNextCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 12) {
	XLOG_ERROR("Wrong number of arguments (%u != 12)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    IPv4 peer_id;
    IPv4Net net;
    uint32_t best_and_origin;
    vector<uint8_t> aspath;
    IPv4 nexthop;
    int32_t med;
    int32_t localpref;
    int32_t atomic_agg;
    vector<uint8_t> aggregator;
    int32_t calc_localpref;
    vector<uint8_t> attr_unknown;
    bool valid;
    try {
	a->get("peer_id", peer_id);
	a->get("net", net);
	a->get("best_and_origin", best_and_origin);
	a->get("aspath", aspath);
	a->get("nexthop", nexthop);
	a->get("med", med);
	a->get("localpref", localpref);
	a->get("atomic_agg", atomic_agg);
	a->get("aggregator", aggregator);
	a->get("calc_localpref", calc_localpref);
	a->get("attr_unknown", attr_unknown);
	a->get("valid", valid);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &peer_id, &net, &best_and_origin, &aspath, &nexthop, &med, &localpref, &atomic_agg, &aggregator, &calc_localpref, &attr_unknown, &valid);
}

bool
XrlBgpV0p2Client::send_get_v6_route_list_next(
	const char*	the_tgt,
	const uint32_t&	token,
	const GetV6RouteListNextCB&	cb
)
{
    Xrl x(the_tgt, "bgp/0.2/get_v6_route_list_next");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlBgpV0p2Client::unmarshall_get_v6_route_list_next, cb));
}


/* Unmarshall get_v6_route_list_next */
void
XrlBgpV0p2Client::unmarshall_get_v6_route_list_next(
	const XrlError&	e,
	XrlArgs*	a,
	GetV6RouteListNextCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 12) {
	XLOG_ERROR("Wrong number of arguments (%u != 12)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    IPv4 peer_id;
    IPv6Net net;
    uint32_t best_and_origin;
    vector<uint8_t> aspath;
    IPv6 nexthop;
    int32_t med;
    int32_t localpref;
    int32_t atomic_agg;
    vector<uint8_t> aggregator;
    int32_t calc_localpref;
    vector<uint8_t> attr_unknown;
    bool valid;
    try {
	a->get("peer_id", peer_id);
	a->get("net", net);
	a->get("best_and_origin", best_and_origin);
	a->get("aspath", aspath);
	a->get("nexthop", nexthop);
	a->get("med", med);
	a->get("localpref", localpref);
	a->get("atomic_agg", atomic_agg);
	a->get("aggregator", aggregator);
	a->get("calc_localpref", calc_localpref);
	a->get("attr_unknown", attr_unknown);
	a->get("valid", valid);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &peer_id, &net, &best_and_origin, &aspath, &nexthop, &med, &localpref, &atomic_agg, &aggregator, &calc_localpref, &attr_unknown, &valid);
}
