PORTNAME=	redis-rails
PORTVERSION=	5.0.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis for Ruby on Rails
WWW=		https://redis-store.org/redis-rails/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-redis-actionpack-rails50>=5.0<6:databases/rubygem-redis-actionpack-rails50 \
		rubygem-redis-activesupport-rails50>=5.0<6:devel/rubygem-redis-activesupport-rails50 \
		rubygem-redis-store>=1.2<2:devel/rubygem-redis-store

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
