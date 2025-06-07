/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *
 *  Created on: Oct 26, 2024
 *      Author: Oscar Rodriguez Polo
 */

/****************************************************************************
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation; either version 2
 *   of the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,USA.
 *
 *
 ****************************************************************************/



#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>

//TODO Complete FT_UAH_PHOTSAT_SERV_129_0010

#define OBT_START_FT_ST129 OBT_AFTER_POWER_ON
#define FT_UAH_PHOTSAT_SERV_129_0010
#define FT_UAH_PHOTSAT_SERV_129_0020

#ifdef FT_UAH_PHOTSAT_SERV_129_0010

// STEP0 - Configura PID con TC[129,2]
EmuGSS_TCProgram129_2 prog_FT_UAH_PHOTSAT_SERV_129_0010_step0( OBT_AFTER_POWER_ON + 0,
    "FT_UAH_PHOTSAT_SERV_129_0010 STEP0: Configura PID (Kp=1.0, Ki=0.0, Kd=0.0)",
    1.0, 0.0, 0.0);

// STEP1 - Ejecuta observación con TC[129,1]
EmuGSS_TCProgram129_1 prog_FT_UAH_PHOTSAT_SERV_129_0010_step1( OBT_AFTER_POWER_ON + 5,
    "FT_UAH_PHOTSAT_SERV_129_0010 STEP1: Ejecuta observación (ThetaPitch=30, ThetaYaw=45,número de imágenes = 3)",
    30,45, 3 );

#endif


//TODO Complete FT_UAH_PHOTSAT_SERV_129_FDIR_0020

#ifdef FT_UAH_PHOTSAT_SERV_129_0020

//defino la monitorización de parámetros (asociación evento 0x4003)
//PMONID,PID, intervalo (HK cada 1s),repeticion, mascara, valor esperado, evento para un valor inesperado
EmuGSS_TCProgram12_5_Value_UINT8 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step0(OBT_AFTER_POWER_ON + 0,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020 STEP0: Configura PMONID 1 para monitorizar ThetaPitch_W_ControlPID (13) ",
    1, 13,1,1,0xFF,0x00,0x4003);

EmuGSS_TCProgram12_5_Value_UINT8 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step1(OBT_AFTER_POWER_ON + 5,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020 STEP1: Configura PMONID 2 para monitorizar ThetaYaw_W_ControlPID (14) ",
    2, 14,1,1,0x00FF,0x00,0x4003);

//habilitamos monitorización
EmuGSS_TCProgram12_1 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step2( OBT_AFTER_POWER_ON + 10,
	"FT_UAH_PHOTSAT_SERV_129_FDIR_0020 STEP2: Habilita PMONID 1", 1);

EmuGSS_TCProgram12_1 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step3(OBT_AFTER_POWER_ON + 15,
	"FT_UAH_PHOTSAT_SERV_129_FDIR_0020 STEP3: Habilita PMONID 2", 2);

// habilitamos el evento 0x4003
EmuGSS_TCProgram19_4 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step4(OBT_AFTER_POWER_ON + 20,
	"FT_UAH_PHOTSAT_SERV_129_FDIR_0020 STEP4: Habilita evento 0x4003", 0x4003);

//Configura PID para exceso de velocidad con TC[129,2]
EmuGSS_TCProgram129_2 prog_FT_UAH_PHOTSAT_SERV_129_0020_step5( OBT_AFTER_POWER_ON + 25,
    "FT_UAH_PHOTSAT_SERV_129_0020 STEP5: Configura PID (Kp=0.5, Ki=0.5, Kd=0.5)",
    0.5, 0.5, 0.5);

// Comanda observación con ángulos alejados de (0,0)
EmuGSS_TCProgram129_1 prog_FT_UAH_PHOTSAT_SERV_129_0020_step6( OBT_AFTER_POWER_ON + 30,
    "STEP6: Observación forzada (ThetaPitch=40, ThetaYaw=35, num_of_samples=3)",
    40, 35, 3);

// Define acción recuperadora: ejecuta TC[129,3] si ocurre el evento 0x4003
EmuGSS_TCProgram19_1_Action_129_3 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step7(OBT_AFTER_POWER_ON + 35,
    "FT_UAH_PHOTSAT_SERV_129_FDIR_0020 STEP7: Acción recuperadora: TC[129,3] ante evento 0x4003",
    0x4003);

#endif

