package mango.rpc;

import mango.common.URL;

/**
 * ${DESCRIPTION}
 *
 *
 */
public interface Node {

    void init();

    void destroy();

    boolean isAvailable();

    String desc();

    URL getUrl();
}
