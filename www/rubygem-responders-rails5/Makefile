PORTNAME=	responders
PORTVERSION=	3.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/heartcombo/responders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack5>=5.0:www/rubygem-actionpack5 \
		rubygem-railties5>=5.0:www/rubygem-railties5

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
