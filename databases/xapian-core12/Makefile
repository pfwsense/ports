PORTNAME=	xapian-core
PORTVERSION=	1.2.25
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	12

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Probabilistic text search database engine
WWW=		https://xapian.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix tar:xz
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	xapian-core # include/xapian.h

PORTSCOUT=	limitw:1,even

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS SSE2

SSE2_DESC=	Use SSE2 for floating point

SSE2_CONFIGURE_ENABLE=	sse

post-install:
.for file in copydatabase delve quest
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${file} ${STAGEDIR}${PREFIX}/bin/xapian-${file}
.endfor

.include <bsd.port.mk>
