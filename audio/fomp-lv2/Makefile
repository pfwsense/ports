PORTNAME=	fomp
DISTVERSION=	1.2.4
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 port of the MCP, VCO, FIL, and WAH plugins by Fons Adriaensen
WWW=		https://drobilla.net/software/fomp.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint

USES=		meson pkgconfig tar:xz
MESON_ARGS=	-Dtests=disabled

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/fomp.lv2/*.so

.include <bsd.port.mk>
