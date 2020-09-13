#include <stdio.h>
#include <stdlib.h>
#include "print_uuid.h"

static const uint32_t density_addr = 0x1FFFF7E0;

static const uint32_t uuid_addr1 = 0x1FFFF7AC;
static const uint32_t uuid_addr2 = 0x1FFFF7B0;
static const uint32_t uuid_addr3 = 0x1FFFF7B4;

#define GET_4BYTE_FROM_ADDR(ADDR)  (*(uint32_t*)ADDR)

void get_uuid()
{
  uint32_t uuid = 0;
  uuid = GET_4BYTE_FROM_ADDR(uuid_addr1);
  printf("uuid1:0x%lx\r\n",uuid);
  uuid = GET_4BYTE_FROM_ADDR(uuid_addr2);
  printf("uuid2:0x%lx\r\n",uuid);
  uuid = GET_4BYTE_FROM_ADDR(uuid_addr3);
  printf("uuid3:0x%lx\r\n",uuid);
}

/*!
 *  \brief      return the ROM/RAM size of this mcu
 *  \param[in]  none
 *  \param[out] none
 *  \retval     the value: High16bit:0x20->32KRAM;Low16bit:0x80->128KROM
 */
uint32_t get_mcu_rom_ram_density()
{
  uint32_t density = GET_4BYTE_FROM_ADDR(density_addr);
//  printf("density:0x%lx\r\n",density);

  return density;
}
