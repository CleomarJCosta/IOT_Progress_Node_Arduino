USING System.Net.Http.*. 
USING System.Environment.

DEFINE VARIABLE HttpClient AS CLASS System.Net.WebClient. 
DEFINE VARIABLE webResponse AS LONGCHAR NO-UNDO.


DEFINE TEMP-TABLE tmpArduino
    FIELD  dados  AS CHAR FORMAT "x(60)" .

FIX-CODEPAGE (webResponse) = "UTF-8". 

HttpClient = NEW System.Net.WebClient(). 
HttpClient:Proxy:Credentials = System.Net.CredentialCache:DefaultNetworkCredentials. 
System.AppContext:SetSwitch("Switch.System.Net.DontEnableSchUseStrongCrypto", false).

webResponse = HttpClient:DownloadString("http://localhost:3000/dados").

HttpClient:Dispose(). 
DELETE OBJECT HttpClient. 
      

CREATE   tmpArduino.                    
    ASSIGN  dados =   STRING(webResponse).

DISPLAY  dados.
                                            

   

