PORTNAME=	fog-cloudstack
PORTVERSION=	0.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support CloudStack
WWW=		https://github.com/fog/fog-cloudstack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=2.1<3:devel/rubygem-fog-core \
		rubygem-fog-json>=1.1<2:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1<1:textproc/rubygem-fog-xml

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
