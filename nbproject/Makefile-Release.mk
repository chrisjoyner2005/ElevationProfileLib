#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/core/ElevationMap.o \
	${OBJECTDIR}/_ext/597559957/Interpolation.o \
	${OBJECTDIR}/_ext/1088103/Quaternion.o \
	${OBJECTDIR}/_ext/1088103/Vector.o \
	${OBJECTDIR}/src/gdal/GDAL_Utilities.o \
	${OBJECTDIR}/_ext/597559957/CoordinateUtils.o \
	${OBJECTDIR}/src/enumerations/Enums.o \
	${OBJECTDIR}/_ext/597383509/DTEM_Image.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/elevationprofilelib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/elevationprofilelib: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -L/usr/local/lib -lgdal -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/elevationprofilelib ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/core/ElevationMap.o: src/core/ElevationMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/ElevationMap.o src/core/ElevationMap.cpp

${OBJECTDIR}/_ext/597559957/Interpolation.o: /Users/marvin_smith1/Documents/ElevationProfileLib/src/math/Interpolation.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/597559957
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/597559957/Interpolation.o /Users/marvin_smith1/Documents/ElevationProfileLib/src/math/Interpolation.cpp

${OBJECTDIR}/_ext/1088103/Quaternion.o: /Users/marvin_smith1/Documents/ElevationProfileLib/src/enumerations/Quaternion.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1088103
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1088103/Quaternion.o /Users/marvin_smith1/Documents/ElevationProfileLib/src/enumerations/Quaternion.cpp

${OBJECTDIR}/_ext/1088103/Vector.o: /Users/marvin_smith1/Documents/ElevationProfileLib/src/enumerations/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1088103
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1088103/Vector.o /Users/marvin_smith1/Documents/ElevationProfileLib/src/enumerations/Vector.cpp

${OBJECTDIR}/src/gdal/GDAL_Utilities.o: src/gdal/GDAL_Utilities.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/gdal
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gdal/GDAL_Utilities.o src/gdal/GDAL_Utilities.cpp

${OBJECTDIR}/_ext/597559957/CoordinateUtils.o: /Users/marvin_smith1/Documents/ElevationProfileLib/src/math/CoordinateUtils.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/597559957
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/597559957/CoordinateUtils.o /Users/marvin_smith1/Documents/ElevationProfileLib/src/math/CoordinateUtils.cpp

${OBJECTDIR}/src/enumerations/Enums.o: src/enumerations/Enums.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/enumerations
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/enumerations/Enums.o src/enumerations/Enums.cpp

${OBJECTDIR}/_ext/597383509/DTEM_Image.o: /Users/marvin_smith1/Documents/ElevationProfileLib/src/gdal/DTEM_Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/597383509
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/597383509/DTEM_Image.o /Users/marvin_smith1/Documents/ElevationProfileLib/src/gdal/DTEM_Image.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/elevationprofilelib

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
