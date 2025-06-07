/*
 * emu_sc_pus_service3.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"

#define TC_129_1_APPDATA_LENGTH 5
#define TC_129_2_APPDATA_LENGTH 12
#define TC_129_3_APPDATA_LENGTH 0


EmuGSS_TCProgram129_1::EmuGSS_TCProgram129_1(uint32_t uniTime2YK,
                         const char * brief,
						 int16_t thetaYaw,
						 int16_t thetaPitch,
						 uint8_t num_of_samples)


	//TODO 6 DONE complete EmuGSS_TCProgram129_1 constructor
:EmuGSS_TCProgram(uniTime2YK,129,1, TC_129_1_APPDATA_LENGTH,brief),
     mThetaYaw(thetaYaw),
     mThetaPitch(thetaPitch),
     mNum_of_samples(num_of_samples)
{
    NewProgram(this);
}

void EmuGSS_TCProgram129_1::BuildTCAppData(tc_mem_descriptor_t &tc_descriptor){

   	//TODO 7 DONE complete EmuGSS_TCProgram129_1::BuildTCAppData code
	// Orden: ThetaPitch (int16_t), ThetaYaw (int16_t), numOfSamples (uint8_t)
    SetNextInt16(mThetaYaw);
    SetNextInt16(mThetaPitch);
    SetNextUInt8(mNum_of_samples);

}


EmuGSS_TCProgram129_2::EmuGSS_TCProgram129_2(uint32_t uniTime2YK,
                         const char * brief,
						 float Kp,
						 float Ki,
						 float Kd)

	//TODO 8 DONE complete EmuGSS_TCProgram129_2 constructor
:EmuGSS_TCProgram(uniTime2YK,129,2, TC_129_2_APPDATA_LENGTH,brief),
mKp(Kp),
mKi(Ki),
mKd(Kd)
{
	NewProgram(this);
}

void EmuGSS_TCProgram129_2::BuildTCAppData(tc_mem_descriptor_t &tc_descriptor){

	//TODO  9 DONE complete EmuGSS_TCProgram129_2::BuildTCAppData code
	  SetNextFloat( mKp);
	  SetNextFloat( mKi);
	  SetNextFloat( mKd);
}


EmuGSS_TCProgram129_3::EmuGSS_TCProgram129_3(uint32_t uniTime2YK,
                         const char * brief)
                        :EmuGSS_TCProgram(uniTime2YK,129,3,
                        		TC_129_3_APPDATA_LENGTH,brief){

    NewProgram(this);
}

EmuGSS_TCProgram129_3::EmuGSS_TCProgram129_3()
                        :EmuGSS_TCProgram(0,129,3,TC_129_3_APPDATA_LENGTH,"NULL"){

	//No Program
    // NewProgram(this);
}


void EmuGSS_TCProgram129_3::BuildTCAppData(tc_mem_descriptor_t &tc_descriptor){



}


