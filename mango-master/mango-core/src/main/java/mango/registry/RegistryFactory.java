package mango.registry;

import mango.common.URL;
import mango.core.extension.SPI;
import mango.core.extension.Scope;

/**
 * ${DESCRIPTION}
 *
 *
 */
@SPI(scope = Scope.SINGLETON)
public interface RegistryFactory {

    Registry getRegistry(URL url);
}
