PORTNAME=	newrelic_rpm
PORTVERSION=	4.7.1.340
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Performance management system for Rails applications
WWW=		https://github.com/newrelic/rpm

LICENSE=	MIT NEWRELIC RUBY
LICENSE_COMB=	multi
LICENSE_NAME_NEWRELIC=	New Relic License
LICENSE_FILE_NEWRELIC=	${WRKSRC}/LICENSE
LICENSE_PERMS_NEWRELIC=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

NO_ARCH=	yes
USES=		gem

PLIST_FILES=	bin/mongrel_rpm bin/newrelic bin/newrelic_cmd bin/nrdebug

.include <bsd.port.mk>
