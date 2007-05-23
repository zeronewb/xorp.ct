/*
 * Copyright (c) 2001-2007 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/static_routes_base.hh,v 1.14 2007/02/16 22:47:58 pavlin Exp $
 */


#ifndef __XRL_TARGETS_STATIC_ROUTES_BASE_HH__
#define __XRL_TARGETS_STATIC_ROUTES_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlStaticRoutesTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlStaticRoutesTargetBase {
protected:
    XrlCmdMap* _cmds;

public:
    /**
     * Constructor.
     *
     * @param cmds an XrlCmdMap that the commands associated with the target
     *		   should be added to.  This is typically the XrlRouter
     *		   associated with the target.
     */
    XrlStaticRoutesTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlStaticRoutesTargetBase();

    /**
     * Set command map.
     *
     * @param cmds pointer to command map to associate commands with.  This
     * argument is typically a pointer to the XrlRouter associated with the
     * target.
     *
     * @return true on success, false if cmds is null or a command map has
     * already been supplied.
     */
    bool set_command_map(XrlCmdMap* cmds);

    /**
     * Get Xrl instance name associated with command map.
     */
    const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    const char* version() const { return "static_routes/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values,
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values,
	string&	version) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get status of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_status(
	// Output values,
	uint32_t&	status,
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Request clean shutdown of Xrl Target
     */
    virtual XrlCmdError common_0_1_shutdown() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target birth to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_birth(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target death to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_death(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Configure a policy filter.
     *
     *  @param filter the identifier of the filter to configure.
     *
     *  @param conf the configuration of the filter.
     */
    virtual XrlCmdError policy_backend_0_1_configure(
	// Input values,
	const uint32_t&	filter,
	const string&	conf) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Reset a policy filter.
     *
     *  @param filter the identifier of the filter to reset.
     */
    virtual XrlCmdError policy_backend_0_1_reset(
	// Input values,
	const uint32_t&	filter) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Push all available routes through all filters for re-filtering.
     */
    virtual XrlCmdError policy_backend_0_1_push_routes() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable/start/stop StaticRoutes.
     *
     *  @param enable if true, then enable StaticRoutes, otherwise disable it.
     */
    virtual XrlCmdError static_routes_0_1_enable_static_routes(
	// Input values,
	const bool&	enable) = 0;

    virtual XrlCmdError static_routes_0_1_start_static_routes() = 0;

    virtual XrlCmdError static_routes_0_1_stop_static_routes() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/replace/delete a static route.
     *
     *  @param unicast if true, then the route would be used for unicast
     *  routing.
     *
     *  @param multicast if true, then the route would be used in the MRIB
     *  (Multicast Routing Information Base) for multicast purpose (e.g.,
     *  computing the Reverse-Path Forwarding information).
     *
     *  @param network the network address prefix this route applies to.
     *
     *  @param nexthop the address of the next-hop router for this route.
     *
     *  @param metric the metric distance for this route.
     */
    virtual XrlCmdError static_routes_0_1_add_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_add_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_replace_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_replace_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_delete_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop) = 0;

    virtual XrlCmdError static_routes_0_1_delete_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/replace/delete a backup static route.
     *
     *  @param unicast if true, then the route would be used for unicast
     *  routing.
     *
     *  @param multicast if true, then the route would be used in the MRIB
     *  (Multicast Routing Information Base) for multicast purpose (e.g.,
     *  computing the Reverse-Path Forwarding information).
     *
     *  @param network the network address prefix this route applies to.
     *
     *  @param nexthop the address of the next-hop router for this route.
     *
     *  @param metric the metric distance for this route.
     */
    virtual XrlCmdError static_routes_0_1_add_backup_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_add_backup_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_replace_backup_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_replace_backup_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_delete_backup_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop) = 0;

    virtual XrlCmdError static_routes_0_1_delete_backup_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/replace/delete a static route by explicitly specifying the network
     *  interface toward the destination.
     *
     *  @param unicast if true, then the route would be used for unicast
     *  routing.
     *
     *  @param multicast if true, then the route would be used in the MRIB
     *  (Multicast Routing Information Base) for multicast purpose (e.g.,
     *  computing the Reverse-Path Forwarding information).
     *
     *  @param network the network address prefix this route applies to.
     *
     *  @param nexthop the address of the next-hop router for this route.
     *
     *  @param ifname of the name of the physical interface toward the
     *  destination.
     *
     *  @param vifname of the name of the virtual interface toward the
     *  destination.
     *
     *  @param metric the metric distance for this route.
     */
    virtual XrlCmdError static_routes_0_1_add_interface_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_add_interface_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_replace_interface_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_replace_interface_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_delete_interface_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname) = 0;

    virtual XrlCmdError static_routes_0_1_delete_interface_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/replace/delete a backup static route by explicitly specifying the
     *  network interface toward the destination.
     *
     *  @param unicast if true, then the route would be used for unicast
     *  routing.
     *
     *  @param multicast if true, then the route would be used in the MRIB
     *  (Multicast Routing Information Base) for multicast purpose (e.g.,
     *  computing the Reverse-Path Forwarding information).
     *
     *  @param network the network address prefix this route applies to.
     *
     *  @param nexthop the address of the next-hop router for this route.
     *
     *  @param ifname of the name of the physical interface toward the
     *  destination.
     *
     *  @param vifname of the name of the virtual interface toward the
     *  destination.
     *
     *  @param metric the metric distance for this route.
     */
    virtual XrlCmdError static_routes_0_1_add_backup_interface_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_add_backup_interface_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_replace_backup_interface_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_replace_backup_interface_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric) = 0;

    virtual XrlCmdError static_routes_0_1_delete_backup_interface_route4(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname) = 0;

    virtual XrlCmdError static_routes_0_1_delete_backup_interface_route6(
	// Input values,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable the StaticRoutes trace log for all operations.
     *
     *  @param enable if true, then enable the trace log, otherwise disable it.
     */
    virtual XrlCmdError static_routes_0_1_enable_log_trace_all(
	// Input values,
	const bool&	enable) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_birth(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_death(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_configure(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_reset(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_push_routes(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_enable_static_routes(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_start_static_routes(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_stop_static_routes(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_add_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_add_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_replace_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_replace_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_delete_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_delete_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_add_backup_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_add_backup_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_replace_backup_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_replace_backup_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_delete_backup_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_delete_backup_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_add_interface_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_add_interface_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_replace_interface_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_replace_interface_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_delete_interface_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_delete_interface_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_add_backup_interface_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_add_backup_interface_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_replace_backup_interface_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_replace_backup_interface_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_delete_backup_interface_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_delete_backup_interface_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_static_routes_0_1_enable_log_trace_all(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif // __XRL_TARGETS_STATIC_ROUTES_BASE_HH__
