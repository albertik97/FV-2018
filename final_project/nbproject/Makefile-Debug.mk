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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Bala.o \
	${OBJECTDIR}/Boss.o \
	${OBJECTDIR}/Button.o \
	${OBJECTDIR}/Camera.o \
	${OBJECTDIR}/Clock.o \
	${OBJECTDIR}/Colisionator.o \
	${OBJECTDIR}/Coords.o \
	${OBJECTDIR}/Enemy.o \
	${OBJECTDIR}/Fondo.o \
	${OBJECTDIR}/Food.o \
	${OBJECTDIR}/Game.o \
	${OBJECTDIR}/Hud.o \
	${OBJECTDIR}/IAActiva.o \
	${OBJECTDIR}/IAPasiva.o \
	${OBJECTDIR}/IAStopped.o \
	${OBJECTDIR}/Keyboard.o \
	${OBJECTDIR}/Motor2D.o \
	${OBJECTDIR}/Mouse.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/Sprite.o \
	${OBJECTDIR}/Text.o \
	${OBJECTDIR}/TileMap.o \
	${OBJECTDIR}/World.o \
	${OBJECTDIR}/credits_state.o \
	${OBJECTDIR}/gameover_state.o \
	${OBJECTDIR}/gamewin_state.o \
	${OBJECTDIR}/ingame_state.o \
	${OBJECTDIR}/intro_state.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/menu_state.o \
	${OBJECTDIR}/options_state.o \
	${OBJECTDIR}/tinystr.o \
	${OBJECTDIR}/tinyxml.o \
	${OBJECTDIR}/tinyxmlerror.o \
	${OBJECTDIR}/tinyxmlparser.o \
	${OBJECTDIR}/transition_state.o


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
LDLIBSOPTIONS=-L/usr/build/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libsfml-system.so /usr/lib/x86_64-linux-gnu/libsfml-graphics.so /usr/lib/x86_64-linux-gnu/libsfml-window.so /usr/lib/x86_64-linux-gnu/libsfml-audio.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final_project

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final_project: /usr/lib/x86_64-linux-gnu/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final_project: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final_project: /usr/lib/x86_64-linux-gnu/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final_project: /usr/lib/x86_64-linux-gnu/libsfml-audio.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final_project: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final_project ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Bala.o: Bala.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bala.o Bala.cpp

${OBJECTDIR}/Boss.o: Boss.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Boss.o Boss.cpp

${OBJECTDIR}/Button.o: Button.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Button.o Button.cpp

${OBJECTDIR}/Camera.o: Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Camera.o Camera.cpp

${OBJECTDIR}/Clock.o: Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Clock.o Clock.cpp

${OBJECTDIR}/Colisionator.o: Colisionator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Colisionator.o Colisionator.cpp

${OBJECTDIR}/Coords.o: Coords.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Coords.o Coords.cpp

${OBJECTDIR}/Enemy.o: Enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Enemy.o Enemy.cpp

${OBJECTDIR}/Fondo.o: Fondo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fondo.o Fondo.cpp

${OBJECTDIR}/Food.o: Food.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Food.o Food.cpp

${OBJECTDIR}/Game.o: Game.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game.o Game.cpp

${OBJECTDIR}/Hud.o: Hud.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hud.o Hud.cpp

${OBJECTDIR}/IAActiva.o: IAActiva.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IAActiva.o IAActiva.cpp

${OBJECTDIR}/IAPasiva.o: IAPasiva.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IAPasiva.o IAPasiva.cpp

${OBJECTDIR}/IAStopped.o: IAStopped.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IAStopped.o IAStopped.cpp

${OBJECTDIR}/Keyboard.o: Keyboard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Keyboard.o Keyboard.cpp

${OBJECTDIR}/Motor2D.o: Motor2D.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor2D.o Motor2D.cpp

${OBJECTDIR}/Mouse.o: Mouse.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mouse.o Mouse.cpp

${OBJECTDIR}/Player.o: Player.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/Sprite.o: Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sprite.o Sprite.cpp

${OBJECTDIR}/Text.o: Text.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Text.o Text.cpp

${OBJECTDIR}/TileMap.o: TileMap.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TileMap.o TileMap.cpp

${OBJECTDIR}/World.o: World.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/World.o World.cpp

${OBJECTDIR}/credits_state.o: credits_state.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/credits_state.o credits_state.cpp

${OBJECTDIR}/gameover_state.o: gameover_state.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gameover_state.o gameover_state.cpp

${OBJECTDIR}/gamewin_state.o: gamewin_state.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gamewin_state.o gamewin_state.cpp

${OBJECTDIR}/ingame_state.o: ingame_state.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ingame_state.o ingame_state.cpp

${OBJECTDIR}/intro_state.o: intro_state.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/intro_state.o intro_state.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/menu_state.o: menu_state.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menu_state.o menu_state.cpp

${OBJECTDIR}/options_state.o: options_state.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/options_state.o options_state.cpp

${OBJECTDIR}/tinystr.o: tinystr.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinystr.o tinystr.cpp

${OBJECTDIR}/tinyxml.o: tinyxml.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxml.o tinyxml.cpp

${OBJECTDIR}/tinyxmlerror.o: tinyxmlerror.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxmlerror.o tinyxmlerror.cpp

${OBJECTDIR}/tinyxmlparser.o: tinyxmlparser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxmlparser.o tinyxmlparser.cpp

${OBJECTDIR}/transition_state.o: transition_state.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iusr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/transition_state.o transition_state.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final_project

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
