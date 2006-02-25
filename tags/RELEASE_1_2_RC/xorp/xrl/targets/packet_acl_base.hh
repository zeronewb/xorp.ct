/*
 * Copyright (c) 2001-2005 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/packet_acl_base.hh,v 1.1 2004/12/10 14:40:18 bms Exp $
 */


#ifndef __XRL_INTERFACES_PACKET_ACL_BASE_HH__
#define __XRL_INTERFACES_PACKET_ACL_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlPacketAclTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlPacketAclTargetBase {
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
    XrlPacketAclTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlPacketAclTargetBase();

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
    inline const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    inline const char* version() const { return "packet_acl/0.0"; }

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
     *  Get the name of the ACL backend currently in use.
     */
    virtual XrlCmdError packet_acl_0_1_get_backend(
	// Output values,
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the underlying packet ACL backend type in use. NOTE: If XORP rules
     *  currently exist, this operation will perform an implicit flush and
     *  reload when switching to the new provider.
     */
    virtual XrlCmdError packet_acl_0_1_set_backend(
	// Input values,
	const string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the underlying packet ACL provider version in use.
     */
    virtual XrlCmdError packet_acl_0_1_get_version(
	// Output values,
	string&	version) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Start ACL transaction.
     *
     *  @param tid the transaction ID returned by this operation.
     */
    virtual XrlCmdError packet_acl_0_1_start_transaction(
	// Output values,
	uint32_t&	tid) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Commit ACL transaction.
     *
     *  @param tid the transaction ID for this operation.
     */
    virtual XrlCmdError packet_acl_0_1_commit_transaction(
	// Input values,
	const uint32_t&	tid) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Abort ACL transaction.
     *
     *  @param tid the transaction ID for this operation.
     */
    virtual XrlCmdError packet_acl_0_1_abort_transaction(
	// Input values,
	const uint32_t&	tid) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add an IPv4 family ACL entry.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param ifname Name of the interface where this filter is to be applied.
     *
     *  @param vifname Name of the vif where this filter is to be applied.
     *
     *  @param src Source IPv4 address with network prefix.
     *
     *  @param dst Destination IPv4 address with network prefix.
     *
     *  @param proto IP protocol number for match (0-255, 255 is wildcard).
     *
     *  @param sport Source TCP/UDP port (0-65535, 0 is wildcard).
     *
     *  @param dport Destination TCP/UDP port (0-65535, 0 is wildcard).
     *
     *  @param action Action taken when this filter is matched.
     */
    virtual XrlCmdError packet_acl_0_1_add_entry4(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src,
	const IPv4Net&	dst,
	const uint32_t&	proto,
	const uint32_t&	sport,
	const uint32_t&	dport,
	const string&	action) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Delete an IPv4 family ACL entry.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param ifname Name of the interface where this filter is to be deleted.
     *
     *  @param vifname Name of the vif where this filter is to be deleted.
     *
     *  @param src Source IPv4 address with network prefix.
     *
     *  @param dst Destination IPv4 address with network prefix.
     *
     *  @param proto IP protocol number for match (0-255, 255 is wildcard).
     *
     *  @param sport Source TCP/UDP port (0-65535, 0 is wildcard).
     *
     *  @param dport Destination TCP/UDP port (0-65535, 0 is wildcard).
     */
    virtual XrlCmdError packet_acl_0_1_delete_entry4(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src,
	const IPv4Net&	dst,
	const uint32_t&	proto,
	const uint32_t&	sport,
	const uint32_t&	dport) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Delete all IPv4 family ACL entries.
     *
     *  @param tid the transaction ID for this operation.
     */
    virtual XrlCmdError packet_acl_0_1_delete_all_entries4(
	// Input values,
	const uint32_t&	tid) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add an IPv6 family ACL entry.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param ifname Name of the interface where this filter is to be applied.
     *
     *  @param vifname Name of the vif where this filter is to be applied.
     *
     *  @param src Source IPv6 address with network prefix.
     *
     *  @param dst Destination IPv6 address with network prefix.
     *
     *  @param proto IP protocol number for match (0-255, 255 is wildcard).
     *
     *  @param sport Source TCP/UDP port (0-65535, 0 is wildcard).
     *
     *  @param dport Destination TCP/UDP port (0-65535, 0 is wildcard).
     *
     *  @param action Action taken when this filter is matched.
     */
    virtual XrlCmdError packet_acl_0_1_add_entry6(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src,
	const IPv6Net&	dst,
	const uint32_t&	proto,
	const uint32_t&	sport,
	const uint32_t&	dport,
	const string&	action) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Delete an IPv6 family ACL entry.
     *
     *  @param tid the transaction ID for this operation.
     *
     *  @param ifname Name of the interface where this filter is to be deleted.
     *
     *  @param vifname Name of the vif where this filter is to be deleted.
     *
     *  @param src Source IPv6 address with network prefix.
     *
     *  @param dst Destination IPv6 address with network prefix.
     *
     *  @param proto IP protocol number for match (0-255, 255 is wildcard).
     *
     *  @param sport Source TCP/UDP port (0-65535, 0 is wildcard).
     *
     *  @param dport Destination TCP/UDP port (0-65535, 0 is wildcard).
     */
    virtual XrlCmdError packet_acl_0_1_delete_entry6(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src,
	const IPv6Net&	dst,
	const uint32_t&	proto,
	const uint32_t&	sport,
	const uint32_t&	dport) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Delete all IPv6 family ACL entries.
     *
     *  @param tid the transaction ID for this operation.
     */
    virtual XrlCmdError packet_acl_0_1_delete_all_entries6(
	// Input values,
	const uint32_t&	tid) = 0;

    virtual XrlCmdError packet_acl_0_1_get_entry_list_start4(
	// Output values,
	uint32_t&	token,
	bool&	more) = 0;

    virtual XrlCmdError packet_acl_0_1_get_entry_list_next4(
	// Input values,
	const uint32_t&	token,
	// Output values,
	string&	ifname,
	string&	vifname,
	IPv4Net&	src,
	IPv4Net&	dst,
	uint32_t&	proto,
	uint32_t&	sport,
	uint32_t&	dport,
	string&	action,
	bool&	more) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_get_backend(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_set_backend(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_start_transaction(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_commit_transaction(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_abort_transaction(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_add_entry4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_delete_entry4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_delete_all_entries4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_add_entry6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_delete_entry6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_delete_all_entries6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_get_entry_list_start4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_packet_acl_0_1_get_entry_list_next4(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif /* __XRL_INTERFACES_PACKET_ACL_BASE_HH__ */