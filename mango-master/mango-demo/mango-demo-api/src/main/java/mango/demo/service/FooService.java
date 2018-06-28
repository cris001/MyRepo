package mango.demo.service;

/**
 * ${DESCRIPTION}
 *
 *
 */
public interface FooService {

    String hello(String name);

    //exception
    String order(String food) throws NullPointerException;

    void pay(String order) throws Exception;
}
