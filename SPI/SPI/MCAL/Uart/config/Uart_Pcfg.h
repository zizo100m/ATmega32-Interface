/*
 * Uart_Pcfg.h
 *
 * Created: 10/21/2021 8:26:17 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef UART_PCFG_H_
#define UART_PCFG_H_


#define UART_MODE_SELECT_BIT       (6U)
#define UART_STOP_BITS_SELECT_BIT  (3U)
#define UART_REGISTER_SELECT_BIT   (7U)
#define UART_DATA_BITS_NUM         (1U)
#define UART_CHAR_SIZE_BIT         (2U)
#define UART_COMM_TYPE_BIT         (3U)
#define UART_DOUBLE_SPEED_BIT      (1U)
#define UART_PARITY_SELECT_BITS    (4U)
#define UART_INT_STATE_BITS        (5U)

/* Communication Flags */
#define UART_DATA_REG_EMPTY_FLAG   (5U)
#define UART_TX_COMPLETE_FLAG      (6U)
#define UART_RX_COMPLETE_FLAG      (7U)



#endif /* UART_PCFG_H_ */
