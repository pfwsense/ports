PORTNAME=	harec
PORTVERSION=	g20230719
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/
DISTNAME=	f16e9792
DIST_SUBDIR=	hare

MAINTAINER=	se@FreeBSD.org
COMMENT=	Hare compiler written in C11
WWW=		https://harelang.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 # aarch64 riscv64

BUILD_DEPENDS=	as:devel/binutils \
		qbe:devel/qbe
RUN_DEPENDS=	as:devel/binutils \
		qbe:devel/qbe

USES=		compiler:c11

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
		${MKDIR} ${WRKSRC}/build
		cd ${WRKSRC}/build && CFLAGS="${CFLAGS}" ../configure --prefix=${PREFIX} && make

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/build/harec ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${STAGEDIR}${DOCSDIR}

do-test:
		cd ${WRKSRC}/build && make check

.include <bsd.port.mk>
