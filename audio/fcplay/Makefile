PORTNAME=	fcplay
PORTVERSION=	0.0.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Future Composer Reference Player

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsidplay.so:audio/libsidplay

USES=		gmake localbase tar:tgz
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/fcplay
PORTDOCS=	ABOUT POINTER

OPTIONS_DEFINE=	DOCS

post-patch:
.for f in configure Config.h.in
	@${REINPLACE_CMD} -e "s@machine/soundcard\.h@sys/soundcard\.h@g; \
		s@HAVE_MACHINE_SOUNDCARD_H@HAVE_SYS_SOUNDCARD_H@g" \
		${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fcplay ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
