#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ndEeprom/ndEeprom.c ndEventBusCircularBuffer/ndEventBusCircularBuffer.c ndEventBusCore/ndEventBusCore.c ndEventBusCore/ndEventBusCoreEventDispatcher.c ndFlash/ndFlash.c ndInternalMemory/ndInternalMemory.c ndLedDriver/ndLedDriver.c ndLedDriver/ndLedDriverEeprom.asm ndLedDriver/ndLedDriverInitFunctions.c ndLedDriver/ndLedDriverEepromFunctions.c ndTimer0/ndTimer0.c ndETimer1/ndTimer1.c ndETimer1.c ndTimer2/ndTimer2.c ndTimer3/ndTimer3.c ndUtils/ndMemoryUtils.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ndEeprom/ndEeprom.p1 ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1 ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1 ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1 ${OBJECTDIR}/ndFlash/ndFlash.p1 ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1 ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1 ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1 ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1 ${OBJECTDIR}/ndTimer0/ndTimer0.p1 ${OBJECTDIR}/ndETimer1/ndTimer1.p1 ${OBJECTDIR}/ndETimer1.p1 ${OBJECTDIR}/ndTimer2/ndTimer2.p1 ${OBJECTDIR}/ndTimer3/ndTimer3.p1 ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1 ${OBJECTDIR}/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ndEeprom/ndEeprom.p1.d ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1.d ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1.d ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1.d ${OBJECTDIR}/ndFlash/ndFlash.p1.d ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1.d ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1.d ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj.d ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1.d ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1.d ${OBJECTDIR}/ndTimer0/ndTimer0.p1.d ${OBJECTDIR}/ndETimer1/ndTimer1.p1.d ${OBJECTDIR}/ndETimer1.p1.d ${OBJECTDIR}/ndTimer2/ndTimer2.p1.d ${OBJECTDIR}/ndTimer3/ndTimer3.p1.d ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1.d ${OBJECTDIR}/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ndEeprom/ndEeprom.p1 ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1 ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1 ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1 ${OBJECTDIR}/ndFlash/ndFlash.p1 ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1 ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1 ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1 ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1 ${OBJECTDIR}/ndTimer0/ndTimer0.p1 ${OBJECTDIR}/ndETimer1/ndTimer1.p1 ${OBJECTDIR}/ndETimer1.p1 ${OBJECTDIR}/ndTimer2/ndTimer2.p1 ${OBJECTDIR}/ndTimer3/ndTimer3.p1 ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1 ${OBJECTDIR}/main.p1

# Source Files
SOURCEFILES=ndEeprom/ndEeprom.c ndEventBusCircularBuffer/ndEventBusCircularBuffer.c ndEventBusCore/ndEventBusCore.c ndEventBusCore/ndEventBusCoreEventDispatcher.c ndFlash/ndFlash.c ndInternalMemory/ndInternalMemory.c ndLedDriver/ndLedDriver.c ndLedDriver/ndLedDriverEeprom.asm ndLedDriver/ndLedDriverInitFunctions.c ndLedDriver/ndLedDriverEepromFunctions.c ndTimer0/ndTimer0.c ndETimer1/ndTimer1.c ndETimer1.c ndTimer2/ndTimer2.c ndTimer3/ndTimer3.c ndUtils/ndMemoryUtils.c main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F2523
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ndEeprom/ndEeprom.p1: ndEeprom/ndEeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndEeprom 
	@${RM} ${OBJECTDIR}/ndEeprom/ndEeprom.p1.d 
	@${RM} ${OBJECTDIR}/ndEeprom/ndEeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndEeprom/ndEeprom.p1  ndEeprom/ndEeprom.c 
	@-${MV} ${OBJECTDIR}/ndEeprom/ndEeprom.d ${OBJECTDIR}/ndEeprom/ndEeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndEeprom/ndEeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1: ndEventBusCircularBuffer/ndEventBusCircularBuffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndEventBusCircularBuffer 
	@${RM} ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1.d 
	@${RM} ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1  ndEventBusCircularBuffer/ndEventBusCircularBuffer.c 
	@-${MV} ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.d ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1: ndEventBusCore/ndEventBusCore.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndEventBusCore 
	@${RM} ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1.d 
	@${RM} ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1  ndEventBusCore/ndEventBusCore.c 
	@-${MV} ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.d ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1: ndEventBusCore/ndEventBusCoreEventDispatcher.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndEventBusCore 
	@${RM} ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1.d 
	@${RM} ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1  ndEventBusCore/ndEventBusCoreEventDispatcher.c 
	@-${MV} ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.d ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndFlash/ndFlash.p1: ndFlash/ndFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndFlash 
	@${RM} ${OBJECTDIR}/ndFlash/ndFlash.p1.d 
	@${RM} ${OBJECTDIR}/ndFlash/ndFlash.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndFlash/ndFlash.p1  ndFlash/ndFlash.c 
	@-${MV} ${OBJECTDIR}/ndFlash/ndFlash.d ${OBJECTDIR}/ndFlash/ndFlash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndFlash/ndFlash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1: ndInternalMemory/ndInternalMemory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndInternalMemory 
	@${RM} ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1.d 
	@${RM} ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1  ndInternalMemory/ndInternalMemory.c 
	@-${MV} ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.d ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndLedDriver/ndLedDriver.p1: ndLedDriver/ndLedDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndLedDriver 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1.d 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndLedDriver/ndLedDriver.p1  ndLedDriver/ndLedDriver.c 
	@-${MV} ${OBJECTDIR}/ndLedDriver/ndLedDriver.d ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1: ndLedDriver/ndLedDriverInitFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndLedDriver 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1.d 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1  ndLedDriver/ndLedDriverInitFunctions.c 
	@-${MV} ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.d ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1: ndLedDriver/ndLedDriverEepromFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndLedDriver 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1.d 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1  ndLedDriver/ndLedDriverEepromFunctions.c 
	@-${MV} ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.d ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndTimer0/ndTimer0.p1: ndTimer0/ndTimer0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndTimer0 
	@${RM} ${OBJECTDIR}/ndTimer0/ndTimer0.p1.d 
	@${RM} ${OBJECTDIR}/ndTimer0/ndTimer0.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndTimer0/ndTimer0.p1  ndTimer0/ndTimer0.c 
	@-${MV} ${OBJECTDIR}/ndTimer0/ndTimer0.d ${OBJECTDIR}/ndTimer0/ndTimer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndTimer0/ndTimer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndETimer1/ndTimer1.p1: ndETimer1/ndTimer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndETimer1 
	@${RM} ${OBJECTDIR}/ndETimer1/ndTimer1.p1.d 
	@${RM} ${OBJECTDIR}/ndETimer1/ndTimer1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndETimer1/ndTimer1.p1  ndETimer1/ndTimer1.c 
	@-${MV} ${OBJECTDIR}/ndETimer1/ndTimer1.d ${OBJECTDIR}/ndETimer1/ndTimer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndETimer1/ndTimer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndETimer1.p1: ndETimer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ndETimer1.p1.d 
	@${RM} ${OBJECTDIR}/ndETimer1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndETimer1.p1  ndETimer1.c 
	@-${MV} ${OBJECTDIR}/ndETimer1.d ${OBJECTDIR}/ndETimer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndETimer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndTimer2/ndTimer2.p1: ndTimer2/ndTimer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndTimer2 
	@${RM} ${OBJECTDIR}/ndTimer2/ndTimer2.p1.d 
	@${RM} ${OBJECTDIR}/ndTimer2/ndTimer2.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndTimer2/ndTimer2.p1  ndTimer2/ndTimer2.c 
	@-${MV} ${OBJECTDIR}/ndTimer2/ndTimer2.d ${OBJECTDIR}/ndTimer2/ndTimer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndTimer2/ndTimer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndTimer3/ndTimer3.p1: ndTimer3/ndTimer3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndTimer3 
	@${RM} ${OBJECTDIR}/ndTimer3/ndTimer3.p1.d 
	@${RM} ${OBJECTDIR}/ndTimer3/ndTimer3.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndTimer3/ndTimer3.p1  ndTimer3/ndTimer3.c 
	@-${MV} ${OBJECTDIR}/ndTimer3/ndTimer3.d ${OBJECTDIR}/ndTimer3/ndTimer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndTimer3/ndTimer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndUtils/ndMemoryUtils.p1: ndUtils/ndMemoryUtils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndUtils 
	@${RM} ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1.d 
	@${RM} ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndUtils/ndMemoryUtils.p1  ndUtils/ndMemoryUtils.c 
	@-${MV} ${OBJECTDIR}/ndUtils/ndMemoryUtils.d ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ndEeprom/ndEeprom.p1: ndEeprom/ndEeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndEeprom 
	@${RM} ${OBJECTDIR}/ndEeprom/ndEeprom.p1.d 
	@${RM} ${OBJECTDIR}/ndEeprom/ndEeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndEeprom/ndEeprom.p1  ndEeprom/ndEeprom.c 
	@-${MV} ${OBJECTDIR}/ndEeprom/ndEeprom.d ${OBJECTDIR}/ndEeprom/ndEeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndEeprom/ndEeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1: ndEventBusCircularBuffer/ndEventBusCircularBuffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndEventBusCircularBuffer 
	@${RM} ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1.d 
	@${RM} ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1  ndEventBusCircularBuffer/ndEventBusCircularBuffer.c 
	@-${MV} ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.d ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndEventBusCircularBuffer/ndEventBusCircularBuffer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1: ndEventBusCore/ndEventBusCore.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndEventBusCore 
	@${RM} ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1.d 
	@${RM} ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1  ndEventBusCore/ndEventBusCore.c 
	@-${MV} ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.d ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndEventBusCore/ndEventBusCore.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1: ndEventBusCore/ndEventBusCoreEventDispatcher.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndEventBusCore 
	@${RM} ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1.d 
	@${RM} ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1  ndEventBusCore/ndEventBusCoreEventDispatcher.c 
	@-${MV} ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.d ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndEventBusCore/ndEventBusCoreEventDispatcher.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndFlash/ndFlash.p1: ndFlash/ndFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndFlash 
	@${RM} ${OBJECTDIR}/ndFlash/ndFlash.p1.d 
	@${RM} ${OBJECTDIR}/ndFlash/ndFlash.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndFlash/ndFlash.p1  ndFlash/ndFlash.c 
	@-${MV} ${OBJECTDIR}/ndFlash/ndFlash.d ${OBJECTDIR}/ndFlash/ndFlash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndFlash/ndFlash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1: ndInternalMemory/ndInternalMemory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndInternalMemory 
	@${RM} ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1.d 
	@${RM} ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1  ndInternalMemory/ndInternalMemory.c 
	@-${MV} ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.d ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndInternalMemory/ndInternalMemory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndLedDriver/ndLedDriver.p1: ndLedDriver/ndLedDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndLedDriver 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1.d 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndLedDriver/ndLedDriver.p1  ndLedDriver/ndLedDriver.c 
	@-${MV} ${OBJECTDIR}/ndLedDriver/ndLedDriver.d ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndLedDriver/ndLedDriver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1: ndLedDriver/ndLedDriverInitFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndLedDriver 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1.d 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1  ndLedDriver/ndLedDriverInitFunctions.c 
	@-${MV} ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.d ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndLedDriver/ndLedDriverInitFunctions.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1: ndLedDriver/ndLedDriverEepromFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndLedDriver 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1.d 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1  ndLedDriver/ndLedDriverEepromFunctions.c 
	@-${MV} ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.d ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndLedDriver/ndLedDriverEepromFunctions.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndTimer0/ndTimer0.p1: ndTimer0/ndTimer0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndTimer0 
	@${RM} ${OBJECTDIR}/ndTimer0/ndTimer0.p1.d 
	@${RM} ${OBJECTDIR}/ndTimer0/ndTimer0.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndTimer0/ndTimer0.p1  ndTimer0/ndTimer0.c 
	@-${MV} ${OBJECTDIR}/ndTimer0/ndTimer0.d ${OBJECTDIR}/ndTimer0/ndTimer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndTimer0/ndTimer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndETimer1/ndTimer1.p1: ndETimer1/ndTimer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndETimer1 
	@${RM} ${OBJECTDIR}/ndETimer1/ndTimer1.p1.d 
	@${RM} ${OBJECTDIR}/ndETimer1/ndTimer1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndETimer1/ndTimer1.p1  ndETimer1/ndTimer1.c 
	@-${MV} ${OBJECTDIR}/ndETimer1/ndTimer1.d ${OBJECTDIR}/ndETimer1/ndTimer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndETimer1/ndTimer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndETimer1.p1: ndETimer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ndETimer1.p1.d 
	@${RM} ${OBJECTDIR}/ndETimer1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndETimer1.p1  ndETimer1.c 
	@-${MV} ${OBJECTDIR}/ndETimer1.d ${OBJECTDIR}/ndETimer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndETimer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndTimer2/ndTimer2.p1: ndTimer2/ndTimer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndTimer2 
	@${RM} ${OBJECTDIR}/ndTimer2/ndTimer2.p1.d 
	@${RM} ${OBJECTDIR}/ndTimer2/ndTimer2.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndTimer2/ndTimer2.p1  ndTimer2/ndTimer2.c 
	@-${MV} ${OBJECTDIR}/ndTimer2/ndTimer2.d ${OBJECTDIR}/ndTimer2/ndTimer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndTimer2/ndTimer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndTimer3/ndTimer3.p1: ndTimer3/ndTimer3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndTimer3 
	@${RM} ${OBJECTDIR}/ndTimer3/ndTimer3.p1.d 
	@${RM} ${OBJECTDIR}/ndTimer3/ndTimer3.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndTimer3/ndTimer3.p1  ndTimer3/ndTimer3.c 
	@-${MV} ${OBJECTDIR}/ndTimer3/ndTimer3.d ${OBJECTDIR}/ndTimer3/ndTimer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndTimer3/ndTimer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ndUtils/ndMemoryUtils.p1: ndUtils/ndMemoryUtils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndUtils 
	@${RM} ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1.d 
	@${RM} ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ndUtils/ndMemoryUtils.p1  ndUtils/ndMemoryUtils.c 
	@-${MV} ${OBJECTDIR}/ndUtils/ndMemoryUtils.d ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ndUtils/ndMemoryUtils.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj: ndLedDriver/ndLedDriverEeprom.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndLedDriver 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj.d 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj 
	${MP_CC} -C $(MP_EXTRA_AS_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"  -o${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj  ndLedDriver/ndLedDriverEeprom.asm 
	@-${MV} ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.d ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj.d 
	@${FIXDEPS} ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj: ndLedDriver/ndLedDriverEeprom.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ndLedDriver 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj.d 
	@${RM} ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj 
	${MP_CC} -C $(MP_EXTRA_AS_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"  -o${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj  ndLedDriver/ndLedDriverEeprom.asm 
	@-${MV} ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.d ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj.d 
	@${FIXDEPS} ${OBJECTDIR}/ndLedDriver/ndLedDriverEeprom.obj.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     --rom=default,-7dc0-7fff --ram=default,-5f4-5ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  -odist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -odist/${CND_CONF}/${IMAGE_TYPE}/firmware.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
