PORTNAME=	File-Find-Rule-VCS
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Exclude files and directories for Version Control Systems
WWW=		https://metacpan.org/release/File-Find-Rule-VCS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Find-Rule>=0.20:devel/p5-File-Find-Rule \
		p5-Text-Glob>=0.08:textproc/p5-Text-Glob

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
