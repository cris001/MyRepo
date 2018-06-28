package mango.rpc;

import mango.core.Request;
import mango.core.Response;

/**
 *
 *
 */
public interface Caller<T> extends Node {

    Class<T> getInterface();

    Response call(Request request);

}
