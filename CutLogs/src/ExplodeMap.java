
import java.sql.ResultSetMetaData;
import java.util.ArrayList;
import javax.xml.transform.Result;   
import org.apache.hadoop.hive.ql.udf.generic.GenericUDTF;
import org.apache.hadoop.hive.ql.exec.UDFArgumentException;
import org.apache.hadoop.hive.ql.exec.UDFArgumentLengthException;
import org.apache.hadoop.hive.ql.metadata.HiveException;
import org.apache.hadoop.hive.serde2.objectinspector.ObjectInspector;
import org.apache.hadoop.hive.serde2.objectinspector.ObjectInspectorFactory;
import org.apache.hadoop.hive.serde2.objectinspector.StructObjectInspector;
import org.apache.hadoop.hive.serde2.objectinspector.primitive.PrimitiveObjectInspectorFactory;




//   download[hdfs:///zeus/hdfs-upload-dir/udf_hive.jar-20160507-191122.jar udf_hive.jar]

   public class ExplodeMap extends GenericUDTF{
  
       @Override
       public void close() throws HiveException {
           // TODO Auto-generated method stub    
       }
  
       @Override
       public StructObjectInspector initialize(ObjectInspector[] args)
               throws UDFArgumentException {
           if (args.length != 1) {
               throw new UDFArgumentLengthException("ExplodeMap takes only one argument");
           }
           if (args[0].getCategory() != ObjectInspector.Category.PRIMITIVE) {
               throw new UDFArgumentException("ExplodeMap takes string as a parameter");
           }
  
           ArrayList<String> fieldNames = new ArrayList<String>();
           ArrayList<ObjectInspector> fieldOIs = new ArrayList<ObjectInspector>();//切割的列数为19列
           fieldNames.add("col1");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col2");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col3");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col4");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col5");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col6");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col7");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col8");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col9");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col10");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col11");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col12");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col13");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col14");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col15");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col16");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col17");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col18");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col19");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col20");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col21");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);
           fieldNames.add("col22");
           fieldOIs.add(PrimitiveObjectInspectorFactory.javaStringObjectInspector);

           return ObjectInspectorFactory.getStandardStructObjectInspector(fieldNames,fieldOIs);
       }
       
       String getMonth(String s){
    	   String t="";
    	   if (s.subSequence(0, 1).equals("J") && s.subSequence(1, 2).equals("a") ) t="01";
    	   if (s.subSequence(0, 1).equals("F")) t="02";
    	   if (s.subSequence(0, 1).equals("M")) t="03";
    	   if (s.subSequence(0, 1).equals("A") && s.subSequence(1, 2).equals("p") ) t="04";
    	   if (s.subSequence(0, 1).equals("M") && s.subSequence(1, 2).equals("a") ) t="05";
    	   if (s.subSequence(0, 1).equals("J") && s.subSequence(3, 4).equals("e") ) t="06";
    	   if (s.subSequence(0, 1).equals("J") && s.subSequence(1, 2).equals("y") ) t="07";
    	   if (s.subSequence(0, 1).equals("A") && s.subSequence(1, 2).equals("u") ) t="08";
    	   if (s.subSequence(0, 1).equals("S")  ) t="09";
    	   if (s.subSequence(0, 1).equals("O")  ) t="10";
    	   if (s.subSequence(0, 1).equals("N") ) t="11";
    	   if (s.subSequence(0, 1).equals("D") ) t="12";
    	   
    	   return t;
       }
       
       String getdate(String s){
    	   String ret="";
    	   String[] t = s.split("/");
    	   int k=s.indexOf(':');
    	   
    	   ret+=t[2].substring(0, 4)+"-";
    	   ret+=getMonth(t[1])+"-";
    	   ret+=t[0].substring(1)+" ";
    	   ret+=s.substring(k+1, k+9);
    	   
    	   return ret;
       }
  
      @Override
       public void process(Object[] args) throws HiveException { 	
    	  
    	  for (int ii=0;ii<args.length;ii++){	  
    		  String input = args[ii].toString();
    		  String[] tmp = input.split("\n");//每条日志的切割的依据是换行符
    		  for (int l=0;l<tmp.length;l++){		  
    			  String[] test = tmp[l].split("\"");//日志中每个字段的分隔符为"
		           String[] ret=test;
		          // ret[0]=test[0];
		           ret[4]=test[1];
		           ret[5]=test[3];
		           ret[6]=test[5];
		           String[] s1=test[0].split(" ");
		           for (int i1=0;i1<4;i1++){
		        	   ret[i1]=s1[i1];
		        	   
		           }
		           
		           
		           int j=6;
		           for(int i=7; i<test.length; i++) {
		        	   if ((i%2) ==1)//由于一个字段有两个引号，每个字段间存在空格，split后需要把空格过滤掉
		        	   {
		        		   ret[++j]=test[i];	        		   
		        	   } 
		           }     
		           String[] test1 = tmp[l].split("\"");
		           ret[6]=getdate(test1[5]);
		           forward(ret);//把结果导出		  
	    	}
	  
	    } 
     }
   }