/*
 * For backwards compatibility.
 *
 * Note to OS vendors: do NOT get rid of this file!  Many applications
 * expect to be able to include <pcap.h>, and at least some of them
 * go through contortions in their configure scripts to try to detect
 * OSes that have "helpfully" moved pcap.h to <pcap/pcap.h> without
 * leaving behind a <pcap.h> file.
 */
#include <pcap/pcap.h>
