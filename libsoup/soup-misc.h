/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * soup-misc.h: Miscellaneous settings and configuration file handling.
 *
 * Authors:
 *      Alex Graveley (alex@ximian.com)
 *
 * Copyright (C) 2000, Helix Code, Inc.
 */

#ifndef SOUP_MISC_H
#define SOUP_MISC_H 1

#include <glib.h>
#include <libsoup/soup-context.h>
#include <libsoup/soup-message.h>
#include <libsoup/soup-uri.h>

void               soup_load_config          (gchar       *config_file);

void               soup_shutdown             (void);

void               soup_set_proxy            (SoupContext *context);

SoupContext       *soup_get_proxy            (void);

void               soup_set_connection_limit (guint        max_conn);

guint              soup_get_connection_limit (void);

typedef enum {
	SOUP_SECURITY_DOMESTIC = 1,
	SOUP_SECURITY_EXPORT   = 2,
	SOUP_SECURITY_FRANCE   = 3
} SoupSecurityPolicy;

void               soup_set_security_policy  (SoupSecurityPolicy policy);

SoupSecurityPolicy soup_get_security_policy  (void);

/* SSL setup routines */

void               soup_set_ssl_ca_file      (gchar       *ca_file);

void               soup_set_ssl_ca_dir       (gchar       *ca_dir);

void               soup_set_ssl_cert_files   (gchar       *cert_file, 
					      gchar       *key_file);

/* Useful debugging routines */

void               soup_debug_print_headers  (SoupMessage *req);

void               soup_debug_print_uri      (SoupUri     *uri);

#endif /* SOUP_MISC_H */
