PORTNAME=	darkplaces
DISTVERSION=	20180412beta1
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/twilight/darkplaces/files/
DISTNAME=	${PORTNAME}engine${DISTVERSION}

PATCH_SITES=	https://gitweb.gentoo.org/repo/gentoo.git/plain/games-fps/darkplaces/files/:gentoo \
		https://raw.githubusercontent.com/gentoo/gentoo/master/games-fps/darkplaces/files/:gentoo
PATCHFILES=	darkplaces-20140513-gcc-11.patch:-p1:gentoo

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake engine modification
WWW=		https://icculus.org/twilight/darkplaces/

LICENSE=	GPLv2+

# Loads libraries at run-time, thus RUN_DEPENDS.
RUN_DEPENDS=	${LOCALBASE}/lib/libvorbis.so:audio/libvorbis

USES=		compiler:c11 gmake jpeg zip
MAKE_ENV=	DP_FS_BASEDIR="${Q1DIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKEFILE=	makefile
ALL_TARGET=	#

OPTIONS_DEFINE=	DOCS SDL1
OPTIONS_MULTI=	MODULE
MODULE_DESC=	Components
OPTIONS_MULTI_MODULE=	GLX SDL SERVER
OPTIONS_DEFAULT=	${OPTIONS_MULTI_MODULE}
OPTIONS_SUB=	yes

GLX_DESC=	Build GLX client
SDL_DESC=	Build SDL client
SDL1_DESC=	Use SDL v1.2 instead of v2.0
SERVER_DESC=	Build dedicated server

GLX_USE=	XORG=x11,xext,xpm,xxf86vm
SDL_USE=	XORG=x11

.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLX} || ${PORT_OPTIONS:MSDL}
USES+=		gl
USE_GL=		glu
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MGLX}
ALL_TARGET+=	cl-release
EXE_TARGETS+=	${PORTNAME}-glx
DESKTOP_ENTRIES+="Darkplaces (GLX client)" "Quake engine modification (GLX)" \
		darkplaces darkplaces-glx "Game;Shooter;" false
.endif

.if ${PORT_OPTIONS:MSERVER}
ALL_TARGET+=	sv-release
EXE_TARGETS+=	${PORTNAME}-dedicated
.endif

.if ${PORT_OPTIONS:MSDL}
USES+=		sdl
. if ${PORT_OPTIONS:MSDL1}
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
. else
USE_SDL=	sdl2
ALL_TARGET+=	sdl-release
. endif
EXE_TARGETS+=	${PORTNAME}-sdl
DESKTOP_ENTRIES+="Darkplaces (SDL client)" "Quake engine modification (SDL)" \
		darkplaces darkplaces-sdl "Game;Shooter;" false
.endif

post-extract:
	@${UNZIP_NATIVE_CMD} ${EXTRACT_BEFORE_ARGS} -d ${WRKDIR} \
		${WRKDIR}/${PORTNAME}enginesource${DISTVERSION}.zip

do-install:
	${INSTALL_PROGRAM} ${EXE_TARGETS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/darkplaces.txt ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MGLX} || ${PORT_OPTIONS:MSDL}
.for i in 16 24 32 48 64 72
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/ && \
	${INSTALL_DATA} ${WRKSRC}/darkplaces${i}x${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/darkplaces.png
.endfor
.endif

.include <bsd.port.mk>
