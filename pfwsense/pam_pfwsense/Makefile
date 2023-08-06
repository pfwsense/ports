PORTNAME=	pam_pfwsense
PORTVERSION=	19.1.3
CATEGORIES=	sysutils

MAINTAINER=	ad@pfwsense.org
COMMENT=	PFWsense shared authentication system using PAM

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	pfwsense

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/lib/*.a

.include <bsd.port.mk>
