PORTNAME=	dhcp6c
DISTVERSION=	20230530
DISTVERSIONPREFIX=v
CATEGORIES=	net

MAINTAINER=	franco@pfwsense.org
COMMENT=	PFWsense WIDE-DHCPv6 client
WWW=		https://github.com/pfwsense/dhcp6c/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

CONFLICTS_INSTALL=	dhcp6

USE_GITHUB=	yes
GH_ACCOUNT=	pfwsense

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc \
		--with-localdbdir=/var/db
USE_RC_SUBR=	dhcp6c

post-install:
	${INSTALL_DATA} ${WRKSRC}/dhcp6c.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
