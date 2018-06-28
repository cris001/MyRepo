package mango.registry;

import mango.common.URL;

import java.util.List;

/**
 *
 */
public interface NotifyListener {

    void notify(URL registryUrl, List<URL> urls);
}
