PORTNAME=	star-history
DISTVERSION=	1.0.12
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graph history of GitHub stars of a user or repo over time
WWW=		https://github.com/dtolnay/star-history

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo ssl

USE_GITHUB=	yes
GH_ACCOUNT=	dtolnay

CARGO_CRATES=	android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anyhow-1.0.71 \
		autocfg-1.1.0 \
		base64-0.21.2 \
		bitflags-1.3.2 \
		bstr-1.5.0 \
		bumpalo-3.13.0 \
		bytes-1.4.0 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		chrono-0.4.26 \
		core-foundation-0.9.3 \
		core-foundation-sys-0.8.4 \
		encoding_rs-0.8.32 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		fastrand-1.9.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.2.0 \
		futures-channel-0.3.28 \
		futures-core-0.3.28 \
		futures-io-0.3.28 \
		futures-sink-0.3.28 \
		futures-task-0.3.28 \
		futures-util-0.3.28 \
		h2-0.3.19 \
		hashbrown-0.12.3 \
		hermit-abi-0.2.6 \
		hermit-abi-0.3.1 \
		home-0.5.5 \
		http-0.2.9 \
		http-body-0.4.5 \
		httparse-1.8.0 \
		httpdate-1.0.2 \
		hyper-0.14.26 \
		hyper-tls-0.5.0 \
		iana-time-zone-0.1.57 \
		iana-time-zone-haiku-0.1.2 \
		idna-0.4.0 \
		indexmap-1.9.3 \
		instant-0.1.12 \
		io-lifetimes-1.0.11 \
		ipnet-2.7.2 \
		itoa-1.0.6 \
		js-sys-0.3.64 \
		lazy_static-1.4.0 \
		libc-0.2.146 \
		linux-raw-sys-0.3.8 \
		log-0.4.19 \
		memchr-2.5.0 \
		mime-0.3.17 \
		mio-0.8.8 \
		native-tls-0.2.11 \
		normpath-1.1.1 \
		num-traits-0.2.15 \
		num_cpus-1.15.0 \
		once_cell-1.18.0 \
		opener-0.6.1 \
		openssl-0.10.55 \
		openssl-macros-0.1.1 \
		openssl-probe-0.1.5 \
		openssl-sys-0.9.90 \
		percent-encoding-2.3.0 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pkg-config-0.3.27 \
		proc-macro2-1.0.60 \
		quote-1.0.28 \
		redox_syscall-0.3.5 \
		regex-automata-0.1.10 \
		reqwest-0.11.18 \
		rustix-0.37.20 \
		ryu-1.0.13 \
		schannel-0.1.21 \
		security-framework-2.9.1 \
		security-framework-sys-2.9.0 \
		serde-1.0.164 \
		serde_derive-1.0.164 \
		serde_json-1.0.97 \
		serde_urlencoded-0.7.1 \
		serde_yaml-0.9.21 \
		slab-0.4.8 \
		socket2-0.4.9 \
		syn-2.0.18 \
		tempfile-3.6.0 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		time-0.1.45 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		tokio-1.28.2 \
		tokio-native-tls-0.3.1 \
		tokio-util-0.7.8 \
		tower-service-0.3.2 \
		tracing-0.1.37 \
		tracing-core-0.1.31 \
		try-lock-0.2.4 \
		unicode-bidi-0.3.13 \
		unicode-ident-1.0.9 \
		unicode-normalization-0.1.22 \
		unsafe-libyaml-0.2.8 \
		url-2.4.0 \
		vcpkg-0.2.15 \
		want-0.3.1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.87 \
		wasm-bindgen-backend-0.2.87 \
		wasm-bindgen-futures-0.4.37 \
		wasm-bindgen-macro-0.2.87 \
		wasm-bindgen-macro-support-0.2.87 \
		wasm-bindgen-shared-0.2.87 \
		web-sys-0.3.64 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.48.0 \
		windows-sys-0.42.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.0 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.48.0 \
		winreg-0.10.1

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
