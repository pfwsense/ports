PORTNAME=	activerecord-session_store
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Dispatch session store backed by an Active Record class
WWW=		https://github.com/rails/activerecord-session_store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=5.2.4.1:www/rubygem-actionpack60 \
		rubygem-activerecord60>=5.2.4.1:databases/rubygem-activerecord60 \
		rubygem-multi_json>=1.11.2<2:devel/rubygem-multi_json \
		rubygem-rack22>=2.0.8,3<3,3:www/rubygem-rack22 \
		rubygem-railties60>=5.2.4.1:www/rubygem-railties60

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
