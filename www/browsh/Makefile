PORTNAME=	browsh
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/browsh-org/browsh/releases/download/${DISTVERSIONFULL}/
DISTNAME=	browsh_${DISTVERSION}_freebsd_${ARCH:S/i386/386/}
EXTRACT_SUFX=	# none

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Text-based browser supporting HTML5, CSS3, JS, video and WebGL
WWW=		https://www.brow.sh/

LICENSE=	LGPL21

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	upstream does not provide binaries for other architerctures

RUN_DEPENDS=	firefox>63:www/firefox

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/browsh

_ALL_DISTFILES=	browsh_${DISTVERSION}_freebsd_386 \
		browsh_${DISTVERSION}_freebsd_amd64 \
		browsh_${DISTVERSION}_freebsd_armv6 \
		browsh_${DISTVERSION}_freebsd_armv7

.if make(makesum) || make(distclean)
DISTFILES:=	${_ALL_DISTFILES}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/browsh

.include <bsd.port.mk>
