from datetime import date

dates = '11/02/2011 15/03/2011 19/12/2010 24/07/2010 09/02/2010 06/02/2010 18/05/2008 22/04/2008 03/10/2007 04/07/2007 01/08/2006 14/05/2006 22/04/2006 16/05/2009 06/07/2003 26/10/2009 29/02/2004 20/03/2004 04/01/2006 25/03/2011 08/11/2010'

dates = dates.split()
newdates = []
for d in dates:
    newdates.append(date(*map(int, d.split('/')[::-1])))

newdates.sort()
for k in range(1, len(newdates)):
    print(newdates[k] - newdates[k - 1])
