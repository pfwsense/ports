PORTNAME=	metasploit-concern
PORTVERSION=	4.0.5
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatically include Modules from app/concerns
WWW=		https://github.com/rapid7/metasploit-concern

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel60>=6.0:databases/rubygem-activemodel60 \
		rubygem-activesupport60>=6.0:devel/rubygem-activesupport60 \
		rubygem-railties60>=6.0:www/rubygem-railties60

NO_ARCH=	yes

USES=		gem

.include <bsd.port.mk>
