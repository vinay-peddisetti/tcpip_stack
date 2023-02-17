
#include "isis_rtr.h"
#include "isis_intf.h"

static void
isis_init(node_t *node);


static void
isis_de_init(node_t *node);

 int
isis_show_handler(param_t *param, ser_buff_t *tlv_buf,
				  op_mode enable_or_disable);

int
isis_config_handler(param_t *param,
					ser_buff_t *tlv_buf,
					op_mode enable_or_disable);

int isis_intf_config_handler(param_t *param, ser_buff_t *tlv_buf,
							 op_mode enable_or_disable);
