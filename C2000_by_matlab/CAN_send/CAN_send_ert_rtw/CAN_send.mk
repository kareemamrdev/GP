###########################################################################
## Makefile generated for component 'CAN_send'. 
## 
## Makefile     : CAN_send.mk
## Generated on : Fri Jun 20 09:23:53 2025
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/CAN_send.out
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = CAN_send
MAKEFILE                  = CAN_send.mk
MATLAB_ROOT               = G:/Matlab/Matlab
MATLAB_BIN                = G:/Matlab/Matlab/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/Projects/GP/C2000_by_matlab/CAN_send
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = TI C28x
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Texas Instruments Code Composer Studio (C2000)
# Supported Version(s):    
# ToolchainInfo Version:   2024a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# CCSINSTALLDIR
# CCSSCRIPTINGDIR
# TARGET_LOAD_CMD_ARGS
# TIF28XXXSYSSWDIR

#-----------
# MACROS
#-----------

TARGET_SCRIPTINGTOOLS_INSTALLDIR = $(CCSSCRIPTINGDIR)
TI_C2000_SHARED_DIR              = $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared
TI_TOOLS                         = $(CCSINSTALLDIR)/bin
TI_INCLUDE                       = $(CCSINSTALLDIR)/include
TI_LIB                           = $(CCSINSTALLDIR)/lib
F28_HEADERS                      = $(TIF28XXXSYSSWDIR)/~SupportFiles/DSP280x_headers
CCOUTPUTFLAG                     = --output_file=
LDOUTPUTFLAG                     = --output_file=
EXE_FILE_EXT                     = $(PROGRAM_FILE_EXT)
PRODUCT_HEX                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_DWO                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).dwo
PRODUCT_ELF                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).elf
DOWN_EXE_JS                      = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/runProgram_generic.js
CCS_CONFIG                       = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/f28x_generic.ccxml
PRODUCT_DEP                      = $(PRODUCT_NAME).txt
DEPFILE_UPDATE                   = $(TI_C2000_SHARED_DIR)/tools/PostBuildDepedency/win64/DepedencyFileUpdate.ps1
SHELL                            = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: C2000 Assembler
AS_PATH = $(TI_TOOLS)
AS = "$(AS_PATH)/cl2000"

# C Compiler: C2000 C Compiler
CC_PATH = $(TI_TOOLS)
CC = "$(CC_PATH)/cl2000"

# Linker: C2000 Linker
LD_PATH = $(TI_TOOLS)
LD = "$(LD_PATH)/cl2000"

# C++ Compiler: C2000 C++ Compiler
CPP_PATH = $(TI_TOOLS)
CPP = "$(CPP_PATH)/cl2000"

# C++ Linker: C2000 C++ Linker
CPP_LD_PATH = $(TI_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/cl2000"

# Archiver: C2000 Archiver
AR_PATH = $(TI_TOOLS)
AR = "$(AR_PATH)/ar2000"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Hex Converter: Hex Converter

# DWO Converter: DWO Converter

# Download: Download
DOWNLOAD_PATH = $(TARGET_SCRIPTINGTOOLS_INSTALLDIR)/bin
DOWNLOAD = "$(DOWNLOAD_PATH)/dss.bat"

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = --output_file=
CDEBUG              = -g
C_OUTPUT_FLAG       = --output_file=
LDDEBUG             =
OUTPUT_FLAG         = --output_file=
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = --output_file=
CPPLDDEBUG          =
OUTPUT_FLAG         = --output_file=
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = -r
ASFLAGS              = --abi=coffabi \
                       -s \
                       -v28 \
                       -ml \
                       $(ASFLAGS_ADDITIONAL)
CFLAGS               = --abi=coffabi \
                       --compile_only \
                       --preproc_dependency="$(@:%.obj=%.dep)" --preproc_with_compile  \
                       --large_memory_model \
                       --silicon_version=28 \
                       --define="LARGE_MODEL" \
                       -I"$(F28_HEADERS)" \
                       -I"$(F28_HEADERS)/include" \
                       -I"$(TI_INCLUDE)"
CPPFLAGS             =
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  =
OBJCOPYFLAGS_DWO     =  "$<"
DOWNLOAD_FLAGS       = $(TARGET_LOAD_CMD_ARGS) $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     =  -i "$<" -o "$@" -order MS -romwidth 16 -q
LDFLAGS              = --abi=coffabi \
                       -z -I$(TI_LIB) \
                       --stack_size=$(STACK_SIZE) --warn_sections \
                       --heap_size=$(HEAP_SIZE) \
                       --reread_libs --rom_model \
                       --priority \
                       -m"$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/CAN_send.out
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/CAN_send_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/c2b/tic2000/inc -I$(MATLAB_ROOT)/toolbox/shared/can/src/scanutil -I$(MATLAB_ROOT)/toolbox/c2b/tic2000/src -I$(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src -I$(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/inc -IG:/DSP/C2000Ware/C2000Ware_5_04_00_00/libraries/calibration/hrpwm/f2837xd/include -IG:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib -IG:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/inc -IG:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/include -IG:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/headers/include -IG:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common -IG:/DSP/C2000Ware/C2000Ware_5_04_00_00/libraries/math/IQmath/c28/include -IG:/DSP/C2000Ware/C2000Ware_5_04_00_00/libraries/math/CLAmath/c28/include -I$(MATLAB_ROOT)/toolbox/c2b/tic2000_soc/src -I$(MATLAB_ROOT)/toolbox/c2b/tic2000_soc/inc

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DMW_PIL_SCIFIFOLEN=16 -DF2837X_REG_FORMAT -DMW_F2837XD -DSTACK_SIZE=1024 -DRT -DF28379D -DCPU1 -DBOOT_FROM_FLASH=1 -DCPU_RAMLS_PROG_START=0x8000 -DCPU_RAMLS_PROG_LENGTH=0x1800 -DCLA_RAMLS_PROG_START=0xA000 -DCLA_RAMLS_PROG_LENGTH=0x1000 -DCLA_RAMLS_DATA_START=0x9800 -DCLA_RAMLS_DATA_LENGTH=0x800
DEFINES_STANDARD = -DMODEL=CAN_send -DNUMST=3 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/CAN_send_ert_rtw/MW_c28xx_csl.c $(START_DIR)/CAN_send_ert_rtw/MW_c28xx_board.c $(START_DIR)/CAN_send_ert_rtw/CAN_send.c $(START_DIR)/CAN_send_ert_rtw/CAN_send_data.c $(START_DIR)/CAN_send_ert_rtw/MW_c28xx_can.c $(START_DIR)/CAN_send_ert_rtw/can_datatype_ground.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/sysctl.c $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/c2837xDBoard_Realtime_Support.c $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/MW_c28xGlobalInterrupts.c $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c2837xDInit.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/dma.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_CpuTimers.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_DefaultISR.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_PieCtrl.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_PieVect.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_SysCtrl.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_usDelay.asm G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_Dma.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_Adc.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_Gpio.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_Ipc_Driver_Lite.c $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c2000HardwareTimerConfig.c $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/MW_c28xGPIO.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/clb.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/libraries/dsp/FPU/c28/source/fpu32/utility/memcpy_fast.asm $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/c2837xDSchedulerTimer0.c $(MATLAB_ROOT)/toolbox/c2b/tic2000_soc/src/mw_soc_c2000_ipc.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/can.c G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/interrupt.c

MAIN_SRC = $(START_DIR)/CAN_send_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_c28xx_csl.obj MW_c28xx_board.obj CAN_send.obj CAN_send_data.obj MW_c28xx_can.obj can_datatype_ground.obj sysctl.obj c2837xDBoard_Realtime_Support.obj MW_c28xGlobalInterrupts.obj c2837xDInit.obj dma.obj F2837xD_CpuTimers.obj F2837xD_DefaultISR.obj F2837xD_GlobalVariableDefs.obj F2837xD_PieCtrl.obj F2837xD_PieVect.obj F2837xD_SysCtrl.obj F2837xD_usDelay.obj F2837xD_CodeStartBranch.obj F2837xD_Dma.obj F2837xD_Adc.obj F2837xD_Gpio.obj F2837xD_Ipc_Driver_Lite.obj c2000HardwareTimerConfig.obj MW_c28xGPIO.obj clb.obj memcpy_fast.obj c2837xDSchedulerTimer0.obj mw_soc_c2000_ipc.obj can.obj interrupt.obj

MAIN_OBJ = ert_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = G:/DSP/C2000Ware/C2000Ware_5_04_00_00/libraries/math/IQmath/c28/lib/IQmath_fpu32.lib $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/c2837xDPeripherals.cmd $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c28377D.cmd

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -v28 --float_support=fpu32 -ml -DF28379D -DCPU1 -DBOOT_FROM_FLASH=1 --tmu_support=tmu0 --fp_mode=relaxed -DCPU_RAMLS_PROG_START=0x8000 -DCPU_RAMLS_PROG_LENGTH=0x1800 -DCLA_RAMLS_PROG_START=0xA000 -DCLA_RAMLS_PROG_LENGTH=0x1000 -DCLA_RAMLS_DATA_START=0x9800 -DCLA_RAMLS_DATA_LENGTH=0x800
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -v28 --float_support=fpu32 -ml -DF28379D -DCPU1 -DBOOT_FROM_FLASH=1 --tmu_support=tmu0 --fp_mode=relaxed -DCPU_RAMLS_PROG_START=0x8000 -DCPU_RAMLS_PROG_LENGTH=0x1800 -DCLA_RAMLS_PROG_START=0xA000 -DCLA_RAMLS_PROG_LENGTH=0x1000 -DCLA_RAMLS_DATA_START=0x9800 -DCLA_RAMLS_DATA_LENGTH=0x800
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F28379D --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_PROG_START=0x8000 --define CPU_RAMLS_PROG_LENGTH=0x1800 --define CLA_RAMLS_PROG_START=0xA000 --define CLA_RAMLS_PROG_LENGTH=0x1000 --define CLA_RAMLS_DATA_START=0x9800 --define CLA_RAMLS_DATA_LENGTH=0x800

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F28379D --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_PROG_START=0x8000 --define CPU_RAMLS_PROG_LENGTH=0x1800 --define CLA_RAMLS_PROG_START=0xA000 --define CLA_RAMLS_PROG_LENGTH=0x1000 --define CLA_RAMLS_DATA_START=0x9800 --define CLA_RAMLS_DATA_LENGTH=0x800

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F28379D --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_PROG_START=0x8000 --define CPU_RAMLS_PROG_LENGTH=0x1800 --define CLA_RAMLS_PROG_START=0xA000 --define CLA_RAMLS_PROG_LENGTH=0x1000 --define CLA_RAMLS_DATA_START=0x9800 --define CLA_RAMLS_DATA_LENGTH=0x800

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F28379D --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_PROG_START=0x8000 --define CPU_RAMLS_PROG_LENGTH=0x1800 --define CLA_RAMLS_PROG_START=0xA000 --define CLA_RAMLS_PROG_LENGTH=0x1000 --define CLA_RAMLS_DATA_START=0x9800 --define CLA_RAMLS_DATA_LENGTH=0x800

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


#-------------------------------------------
# Post build updates - DEP, HEX, DWO/ELF
#-------------------------------------------
all :
ifeq ($(DEPRULES),1)
#--------------------------
# Dependency file updates
#--------------------------
postbuild : $(PRODUCT_DEP)

$(PRODUCT_DEP): $(PRODUCT)
	@echo "### Updating dependency files ..."
	PowerShell -ExecutionPolicy Bypass -command "& '$(DEPFILE_UPDATE)'"
	@echo "### Done Updating dependency files ..."
endif

ifeq ($(PRODUCT_TYPE),"executable")
#--------------------------
# ELF to hex converter
#--------------------------
postbuild : $(PRODUCT_HEX)

$(PRODUCT_HEX): $(PRODUCT)
	@echo "### Invoking postbuild tool "Hex Converter" on "$<"..."
	$(CCSINSTALLDIR)/bin/hex2000 $(OBJCOPYFLAGS_HEX)
	@echo "### Done Invoking postbuild tool "Hex Converter" ..."

#--------------------------
# DWO converter
#--------------------------
postbuild : $(PRODUCT_DWO)

$(PRODUCT_DWO): $(PRODUCT)
	@echo "### Invoking postbuild tool "DWO Converter" on "$<"..."
	$(TI_C2000_SHARED_DIR)/tools/bin/win64/extractDWARF.exe $(OBJCOPYFLAGS_DWO)
	@echo "### Done Invoking postbuild tool "DWO Converter" ..."

endif

#--------------------------
# Dependency based build rule
#--------------------------
ifeq ($(DEPRULES),1) 
ALL_DEPS:=$(patsubst %.obj,%.d,$(ALL_OBJS))
all:
else
ALL_DEPS:=
endif




-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)


download : postbuild
	@echo "### Invoking postbuild tool "Download" ..."
	$(DOWNLOAD) $(DOWNLOAD_FLAGS)
	@echo "### Done invoking postbuild tool."


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) --output_file=$(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/CAN_send_ert_rtw/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/CAN_send_ert_rtw/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/CAN_send_ert_rtw/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/CAN_send_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


MW_c28xx_csl.obj : $(START_DIR)/CAN_send_ert_rtw/MW_c28xx_csl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_board.obj : $(START_DIR)/CAN_send_ert_rtw/MW_c28xx_board.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


CAN_send.obj : $(START_DIR)/CAN_send_ert_rtw/CAN_send.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


CAN_send_data.obj : $(START_DIR)/CAN_send_ert_rtw/CAN_send_data.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_can.obj : $(START_DIR)/CAN_send_ert_rtw/MW_c28xx_can.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


can_datatype_ground.obj : $(START_DIR)/CAN_send_ert_rtw/can_datatype_ground.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


ert_main.obj : $(START_DIR)/CAN_send_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


sysctl.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/sysctl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2837xDBoard_Realtime_Support.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/c2837xDBoard_Realtime_Support.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGlobalInterrupts.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/MW_c28xGlobalInterrupts.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2837xDInit.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c2837xDInit.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


dma.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/dma.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_CpuTimers.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_CpuTimers.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_DefaultISR.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_DefaultISR.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_GlobalVariableDefs.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_PieCtrl.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_PieCtrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_PieVect.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_PieVect.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_SysCtrl.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_SysCtrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_usDelay.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_usDelay.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


F2837xD_CodeStartBranch.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


F2837xD_Dma.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_Dma.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_Adc.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_Adc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_Gpio.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_Gpio.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_Ipc_Driver_Lite.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/device_support/f2837xd/common/source/F2837xD_Ipc_Driver_Lite.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2000HardwareTimerConfig.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c2000HardwareTimerConfig.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGPIO.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/MW_c28xGPIO.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


clb.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/clb.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


memcpy_fast.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/libraries/dsp/FPU/c28/source/fpu32/utility/memcpy_fast.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


c2837xDSchedulerTimer0.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/c2837xDSchedulerTimer0.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


mw_soc_c2000_ipc.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_soc/src/mw_soc_c2000_ipc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


can.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/can.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


interrupt.obj : G:/DSP/C2000Ware/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/interrupt.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### OBJCOPYFLAGS_DWO = $(OBJCOPYFLAGS_DWO)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *Object
	$(ECHO) "### Deleted all derived files."


