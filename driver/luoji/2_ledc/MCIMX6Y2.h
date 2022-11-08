/*
 * IOMUX寄存器
 */

typedef struct  
{ 
    volatile unsigned int BOOT_MODE0; 
    volatile unsigned int BOOT_MODE1; 
    volatile unsigned int SNVS_TAMPER0; 
    volatile unsigned int SNVS_TAMPER1;   
      
    volatile unsigned int CSI_DATA00; 
    volatile unsigned int CSI_DATA01; 
    volatile unsigned int CSI_DATA02; 
    volatile unsigned int CSI_DATA03; 
    volatile unsigned int CSI_DATA04; 
    volatile unsigned int CSI_DATA05; 
    volatile unsigned int CSI_DATA06; 
    volatile unsigned int CSI_DATA07; 
   /* 为了缩短代码，其余 IO复用寄存器省略 */ 
}IOMUX_SW_MUX_Tpye; 
