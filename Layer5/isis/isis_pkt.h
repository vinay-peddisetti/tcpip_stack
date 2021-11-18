#ifndef __ISIS_PKT__
#define __ISIS_PKT__

typedef uint16_t isis_pkt_type_t;
typedef uint8_t  isis_pkt_hdr_flags_t;

typedef struct isis_pkt_ {

    /* The wired form of pkt */
    byte *pkt;
    /* pkt size, including eithernet hdr */
    size_t pkt_size;

    /* glue to attach this lsp pkt to lspdb*/
    avltree_node_t avl_node_glue;
    bool installed_in_db;
    /* Ref_count */
    uint16_t ref_count;
     /* Life time timer */
    timer_event_handle *expiry_timer;
} isis_lsp_pkt_t;


#pragma pack (push,1)
typedef struct isis_pkt_hdr_{

    isis_pkt_type_t isis_pkt_type;
    uint32_t seq_no; 
    uint32_t rtr_id;
    isis_pkt_hdr_flags_t flags;
} isis_pkt_hdr_t;
#pragma pack(pop)

byte *
isis_prepare_hello_pkt(interface_t *intf, size_t *hello_pkt_size);

bool
isis_pkt_trap_rule (char *pkt, size_t pkt_size);

void
isis_pkt_receive(void *arg, size_t arg_size) ;

uint32_t
isis_print_hello_pkt(byte *buff, 
                                  isis_pkt_hdr_t *hello_pkt_hdr,
                                  uint32_t pkt_size ) ;
                                  
uint32_t
isis_print_lsp_pkt(byte *buff, 
                                  isis_pkt_hdr_t *hello_pkt_hdr,
                                  uint32_t pkt_size ) ;

void
isis_print_pkt(void *arg, size_t arg_size);

void
isis_create_fresh_lsp_pkt(node_t *node);

void
isis_deref_isis_pkt(isis_lsp_pkt_t *lsp_pkt);

void
isis_ref_isis_pkt(isis_lsp_pkt_t *isis_pkt) ;

#endif 
