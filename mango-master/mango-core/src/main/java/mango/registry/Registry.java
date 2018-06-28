package mango.registry;

import mango.common.URL;

/**
 * ${DESCRIPTION}
 *
 *
 */
public interface Registry extends RegistryService, DiscoveryService {

    URL getUrl();

    void close();
}
