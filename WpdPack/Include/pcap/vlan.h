#ifndef lib_pcap_vlan_h
#define lib_pcap_vlan_h

struct vlan_tag {
	u_int16_t	vlan_tpid;		/* ETH_P_8021Q */
	u_int16_t	vlan_tci;		/* VLAN TCI */
};

#define VLAN_TAG_LEN	4

#endif
