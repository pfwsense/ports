PORTNAME=	Monitoring-Plugin
PORTVERSION=	0.40
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NIERLEIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Modules to streamline writing Monitoring plugins
WWW=		https://metacpan.org/dist/Monitoring-Plugin

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Math-Calc-Units>=0:math/p5-Math-Calc-Units \
		p5-Config-Tiny>=0:devel/p5-Config-Tiny

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
