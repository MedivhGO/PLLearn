min = 507500.0
max = 33000000.0
bins = 10

def get_thresholds(min, max, bins):
    x = []
    step=(max-min)/bins 
    for i in range(bins):
        x.append(round(i*step,2)+min)
    return x

ths = get_thresholds(min,max,bins)

def histogram(ths, variable):
    q = []
    q.append("SELECT CASE ")
    for i in range(len(ths)-1):
        q_i =" WHEN "+variable+" >= " + str(ths[i]) +" AND " +variable+ " < "+ str(ths[i+1])+" THEN "+ str(ths[i+1]) 
        q.append(q_i)
    q.append(" WHEN  "+variable+" >= " + str(ths[i+1]) + " THEN "+ str(33000000.0))
    q.append(" ELSE NULL END as Score ")
    return q

variable = " salary "
q = histogram(ths,variable)

for i in range(len(q)):
    print(q[i])