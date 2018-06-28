package mango.rpc;

/**
 * ${DESCRIPTION}
 *
 *
 */
public interface Exporter<T> extends Node {

    Provider<T> getProvider();

    void unexport();
}
