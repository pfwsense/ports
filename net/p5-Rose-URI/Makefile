PORTNAME=	Rose-URI
PORTVERSION=	1.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JSIRACUSA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy and efficient manipulation of URI components
WWW=		https://metacpan.org/release/Rose-URI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Rose-Object>=0.854:devel/p5-Rose-Object \
		p5-URI>0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
