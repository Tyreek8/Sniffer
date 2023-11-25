#ifndef _PCAP_BLUETOOTH_STRUCTS_H__
#define _PCAP_BLUETOOTH_STRUCTS_H__

/*
 * Header prepended libpcap to each bluetooth h:4 frame.
 * fields are in network byte order
 */
typedef struct _pcap_bluetooth_h4_header {
	u_int32_t direction; /* if first bit is set direction is incoming */
} pcap_bluetooth_h4_header;


#endif
