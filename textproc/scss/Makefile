PORTNAME=	scss
PORTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	textproc scheme
MASTER_SITES=	SAVANNAH \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Scheme module for W3C Cascading Stylesheets recommendation
WWW=		https://www.nongnu.org/scss/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	guile:lang/guile

NO_BUILD=	yes
NO_ARCH=	yes

FILES=		lexer.scm parser.scm scss.scm properties.scm \
		interface/sdom.scm common.scm
INFO=		scss

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/guile/scss
.for f in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/share/guile/scss
.endfor
	${INSTALL_DATA} ${WRKSRC}/scss.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
