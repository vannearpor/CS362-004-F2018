/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import junit.framework.TestCase;

public class UrlValidatorTest extends TestCase {
    
    private boolean printStatus = false;
    private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.
    private static int assertCheck = 0;
    public UrlValidatorTest(String testName) {
        super(testName);
    }
    
    static public void assertFalse(String message, boolean validate){
        if(validate != false) {
            System.out.println("Error: " + message);
            assertCheck++;
        }
    }
    static public void assertTrue(String message, boolean validate){
        if(validate != true) {
            System.out.println("Error: " + message);
            assertCheck++;
        }
    }
    public void testManualTest()
    {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        System.out.println(urlVal.isValid("http://www.google.com"));
        System.out.println(urlVal.isValid("http://ww.google.com"));
        System.out.println(urlVal.isValid("http/www.google.com"));
        System.out.println(urlVal.isValid("http://www.googlecom"));
        System.out.println(urlVal.isValid("http://wwww.google.com"));
        System.out.println(urlVal.isValid("1.com"));
        System.out.println(urlVal.isValid("a.com"));
        System.out.println(urlVal.isValid("abc."));
        System.out.println(urlVal.isValid("z.co"));
        System.out.println(urlVal.isValid("z.com"));
        System.out.println(urlVal.isValid("www..com"));
        System.out.println(urlVal.isValid("http://www..com"));
        System.out.println(urlVal.isValid("twitter.co"));
        System.out.println(urlVal.isValid("http://en.wikipedia.org"));
        System.out.println(urlVal.isValid("http://en.wikipediA.org"));
        System.out.println(urlVal.isValid("http://en.wikipedia.org/wiki/Oregon_State_University"));
        System.out.println(urlVal.isValid("http://en.wikipediA.org"));
        System.out.println(urlVal.isValid("http:/en.wikipediA.org"));
        System.out.println(urlVal.isValid("http//en.wikipediA.org"));
        System.out.println(urlVal.isValid("http:///en.wikipedia.org"));
        System.out.println(urlVal.isValid("http://www.en.wikipediA.org"));
        System.out.println(urlVal.isValid("http://wwwwwwww.en.wikipediA.org"));
        System.out.println(urlVal.isValid("http://w.en.wikipediA.org"));
        System.out.println(urlVal.isValid("http://org.en.wikipediA.www"));
        System.out.println(urlVal.isValid("http://en.wikipediA.org"));
        System.out.println(urlVal.isValid("http://rrr.en.wikipediA.org"));
        System.out.println(urlVal.isValid("http://WWW.en.wikipediA.org"));
        System.out.println(urlVal.isValid("http://en.wikipedi>A.org"));
        System.out.println(urlVal.isValid("http://en.wikipediA.oRg"));
        System.out.println(urlVal.isValid("http://en.wiki?pediA.org"));
        System.out.println(urlVal.isValid("http://en.wiki[p]ediA.org"));
        System.out.println(urlVal.isValid("http://en.wik'i'pediA.org"));
        System.out.println(urlVal.isValid("http://en.w>ikipediA.org"));
        System.out.println(urlVal.isValid("http://en.wikipediA0.org"));
        System.out.println(urlVal.isValid("http://www.1234.com"));
        System.out.println(urlVal.isValid("http://en.wikipediA.org"));
        System.out.println(urlVal.isValid("http://www.oregonstate.edu"));
        System.out.println(urlVal.isValid("www.oregonstate.edu"));
        System.out.println(urlVal.isValid("http://twitter.com/"));
        System.out.println(urlVal.isValid("http://w.twitter.com/"));
        System.out.println(urlVal.isValid("http://ww.twitter.com/"));
        System.out.println(urlVal.isValid("http://wwwwww.twitter.com/"));
        System.out.println(urlVal.isValid("http://d.twitter.com/"));
    }
    
    
    public void testYourFirstPartition()
    {
        //You can use this function to implement your First Partition testing
        System.out.println("Scheme tests:");
        assertCheck = 0;
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        
        assertFalse("Scheme SHOULD NOT validate: h@@@ttp://www.google.com",urlVal.isValid("h@@@ttp://www.google.com"));
        assertFalse("Scheme SHOULD NOT validate: 95http://www.google.com",urlVal.isValid("95http://www.google.com"));
        assertFalse("Scheme SHOULD NOT validate: 00http://www.google.com",urlVal.isValid("00http://www.google.com"));
        
        assertTrue("Scheme SHOULD validate: http://www.google.com",urlVal.isValid("http://www.google.com"));
        assertTrue("Scheme SHOULD validate: ftp://www.google.com",urlVal.isValid("ftp://www.google.com"));
        assertTrue("Scheme SHOULD validate: https://www.google.com",urlVal.isValid("https://www.google.com"));
        assertTrue("Scheme SHOULD validate: ftps://www.google.com",urlVal.isValid("ftps://www.google.com"));
        assertTrue("Scheme SHOULD validate: telnet://www.google.com",urlVal.isValid("telnet://www.google.com"));
        
        if(assertCheck > 0)
            fail("The scheme partitioned tests failed");
        else
            System.out.println("The scheme partitioned tests succeeded");
    }
    
    public void testYourSecondPartition(){
        //You can use this function to implement your Second Partition testing
        
        System.out.println("Path tests:");
        assertCheck = 0;
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        
        assertFalse("Path SHOULD NOT validate: http://www.google.com/boat/////items",urlVal.isValid("http://www.google.com/boat/////items"));
        assertFalse("Path SHOULD NOT validate: http://www.google.com///pathquery",urlVal.isValid("http://www.google.com///pathquery"));
        assertFalse("Path SHOULD NOT validate: http://www.google.combs.",urlVal.isValid("http://www.google.combs."));
        assertFalse("Path SHOULD NOT validate: http://www.google.com//incorrectformatting",urlVal.isValid("http://www.google.com//incorrectformatting"));
        
        assertTrue("Path SHOULD validate: http://www.google.com/boat/items",urlVal.isValid("http://www.google.com/boat/items"));
        assertTrue("Path SHOULD validate: http://www.google.com/boat/items#",urlVal.isValid("http://www.google.com/boat/items#"));
        assertTrue("Path SHOULD validate: http://www.google.com/thisoneworks",urlVal.isValid("http://www.google.com/thisoneworks"));
        assertTrue("Path SHOULD validate: http://www.google.com",urlVal.isValid("http://www.google.com"));
        assertTrue("Path SHOULD validate: http://www.google.com/88/lastone",urlVal.isValid("http://www.google.com/88/lastone"));
        
        if(assertCheck > 0)
            fail("The path partitioned tests failed");
        else
            System.out.println("The path partitioned tests succeeded");
    }
    
    //You need to create more test cases for your Partitions if you need to
    
    public void testYourThirdPartition() {//PARTITION 3: PORT
        System.out.println("Port tests:");
        assertCheck = 0;
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        
        assertFalse("Port SHOULD NOT validate: http://www.google.com:-99999999",urlVal.isValid("http://www.google.com:-99999999"));
        assertFalse("Port SHOULD NOT validate: http://www.google.com:99999999",urlVal.isValid("http://www.google.com:99999999"));
        assertFalse("Port SHOULD NOT validate: http://www.google.com:$@#$#%@#",urlVal.isValid("http://www.google.com:$@#$#%@#"));
        assertFalse("Port SHOULD NOT validate: http://www.google.com:words",urlVal.isValid("http://www.google.com:words"));
        assertFalse("Port SHOULD NOT validate: http://www.google.com:-99",urlVal.isValid("http://www.google.com:-99"));
        
        assertTrue("Port SHOULD validate: http://www.google.com:0",urlVal.isValid("http://www.google.com:0"));
        assertTrue("Port SHOULD validate: http://www.google.com:1",urlVal.isValid("http://www.google.com:1"));
        assertTrue("Port SHOULD validate: http://www.google.com:1000",urlVal.isValid("http://www.google.com:1000"));
        assertTrue("Port SHOULD validate: http://www.google.com:10000",urlVal.isValid("http://www.google.com:10000"));
        
        if(assertCheck > 0)
            fail("The port partitioned tests have failed");
        else
            System.out.println("Success");
    }
    
    public void testIsValid()
    {
        String current_URL;
        boolean validFlag;
        
        String URL_schemes[] = new String [8];
        URL_schemes[0]= "http://";
        URL_schemes[1]= "https://";
        URL_schemes[2]= "ftp://";
        URL_schemes[3]= "h3t://";
        URL_schemes[4]= "";
        URL_schemes[5]= "fhdsjakjfd:::///";
        URL_schemes[6]= "invalidScheme/:/";
        URL_schemes[7]= "thpthtphttph://";
        
        UrlValidator create_URL = new UrlValidator(URL_schemes, null, UrlValidator.ALLOW_2_SLASHES);
        
        String URL_authority[] = new String [6];
        URL_authority[0]= "fakewebsite";
        URL_authority[1]= "123fake456.f4k3";
        URL_authority[2]= "invalid.101";
        URL_authority[3]= "www.oregonstate.edu";
        URL_authority[4]= "yahoo.com";
        URL_authority[5]= "66.220.159.255";
        
        String URL_portnum[] = new String [5];
        URL_portnum[0]= ":60000";
        URL_portnum[1]= ":2000";
        URL_portnum[2]= ":80";
        URL_portnum[3]= ":abc123youknowme";
        URL_portnum[4]= ":doesthiswork?";
        
        String URL_path[] = new String [5];
        URL_path[0]= "/./../..../../";
        URL_path[1]= "/%$#@$%/";
        URL_path[2]= "/directory/home";
        URL_path[3]= "/aboutme";
        URL_path[4]= "/contact/download";
        
        String URL_query[] = new String [3];
        URL_query[0] = "?search=applepie";
        URL_query[1] = "notaqueryatall";
        URL_query[2] = "is?this?a?query?=?";
        
        int scheme, auth, port, path, query;
        
        for(scheme = 0; scheme < 8; scheme++){
            for(auth = 0; auth < 6; auth++){
                for(port = 0; port < 5; port++){
                    for(path = 0; path < 5; path++){
                        for(query = 0; query < 3; query++){
                            
                            current_URL = URL_schemes[scheme] + URL_authority[auth] + URL_portnum[port] + URL_path[path] + URL_query[query];
                            
                            if((scheme < 5) && (auth > 2) && (port < 3) && (path > 1) && (query == 0)) {
                                validFlag = create_URL.isValid(current_URL);
                                System.out.println("Test Passed!");
                                System.out.println(current_URL);
                            }
                            else{
                                validFlag = false;
                                System.out.println("Test Failed.");
                            }
                        }
                    }
                }
            }
        }
    }
}

