#include<stdio.h>
int main()
{
	int a=266;
	char c;
	c=a;
	printf("%d\n",c);
}

//电流的小数位数读取
void CMeterDLT614::cmd_mt_power_pot_deal(CSmpData *smp_data, uint32 base_num, uint8 *data, CP56Time2a time)
{
    float f_temp;
    uint8 uc_temp;
    uint16 us_temp;
    DB_Record db_temp;
    uint32 ui_temp;
    uint32 ui_offset = ( METER_DATA_POS+4);       
    ui_temp = bcd2int(data+ui_offset, 2);
    m_st_sample_data_now.power_pot_pos = (char )ui_temp;
    DbgPrintf("  ANA_MT_VOLTAGE_A setting: %d\n", (char )ui_temp);  
    db_temp.l_point_num  = pw_point_num(base_num, METER_DEVICE_NUM, ANA_MT_VOLTAGE_A, 0);
    db_temp.ui_base_num  = base_num;
    db_temp.us_data_len  = 4;
    db_temp.uc_data_type = TYPE_CHAR;
    cpy_cp56time(&(db_temp.st_time), time);
    db_temp.uc_upload_flag = 0;
    memcpy(db_temp.uc_data, (uint8 *)&ui_temp, 1);
    smp_data->push(db_temp);
}

//电压的小数位数读取
void CMeterDLT614::cmd_mt_enenrgy_pot_deal(CSmpData *smp_data, uint32 base_num, uint8 *data, CP56Time2a time)
{
    float f_temp;
    uint8 uc_temp;
    uint16 us_temp;
    DB_Record db_temp;
    uint32 ui_temp;
    uint32 ui_offset = ( METER_DATA_POS+4);       
    ui_temp = bcd2int(data+ui_offset, 2);
    m_st_sample_data_now.energy_pot_pos= (char )ui_temp;
    DbgPrintf("  ANA_MT_VOLTAGE_A setting: %d\n", f_temp);  
    db_temp.l_point_num  = pw_point_num(base_num, METER_DEVICE_NUM, ANA_MT_VOLTAGE_A, 0);
    db_temp.ui_base_num  = base_num;
    db_temp.us_data_len  = 1;
    db_temp.uc_data_type = TYPE_CHAR;
    cpy_cp56time(&(db_temp.st_time), time);
    db_temp.uc_upload_flag = 0;
    memcpy(db_temp.uc_data, (uint8 *)&f_temp, 1);
    smp_data->push(db_temp);
}
