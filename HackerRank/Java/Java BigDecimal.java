        //Write your code here
        Arrays.sort(s,new Comparator<String>(){

            public int compare(String a1,String a2) {
                if ( a1 == null || a2 == null )
                    return 0;
                BigDecimal aa1 = new BigDecimal(a1);
                BigDecimal aa2 = new BigDecimal(a2);

                return aa2.compareTo(aa1);
            }

        });

    //https://www.hackerrank.com/challenges/java-bigdecimal/problem