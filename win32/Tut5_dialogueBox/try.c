#include <windows.h>
#include <stdio.h>
#include <string.h>




struct UserPassGetter {
  char* user, pwd;
  int got;
};

string GetInputText( HWND dlg, int resid  ) {
  HWND hc = GetDlgItem( dlg, resid );
  int n = GetWindowTextLength( hc ) + 1;
  string s( n, 0 );
  GetWindowText( hc, &s[0], n );
  return s;
}

BOOL CALLBACK DialogProc( HWND hwnd, UINT message,
                           WPARAM wp, LPARAM lp  ) {
  static UserPassGetter * getter = 0;
  switch ( message ) { 
    case WM_INITDIALOG:
	  getter = (UserPassGetter *) lp;
	  return TRUE;
    case WM_COMMAND: {
	  int ctl = LOWORD( wp ); 
      int event = HIWORD( wp );
      if ( ctl == IDCANCEL && event == BN_CLICKED ) {
	getter->got = false;
  	DestroyWindow (hwnd);
	return TRUE;     
      }

      else if ( ctl == IDOK && event == BN_CLICKED ) {
        getter->user = GetInputText( hwnd, IDC_USEREDIT );
        getter->pwd = GetInputText( hwnd, IDC_PWDEDIT );
        getter->got = true;
        DestroyWindow (hwnd);
        return TRUE;
      }
      return FALSE;
    }
    case WM_DESTROY:         
       PostQuitMessage(0);         
       return TRUE;
    case WM_CLOSE:
       DestroyWindow (hwnd);
       return TRUE;     
   }
   return FALSE;
}

void UserPassGetter :: Get() {
  HWND dlg = CreateDialogParam( GetModuleHandle(0),
                                MAKEINTRESOURCE( IDD_PWDDLG  ), 
                                0, DialogProc, (LPARAM) this );
  MSG msg;
  while ( GetMessage( & msg, 0, 0, 0 ) ) {
    if ( ! IsDialogMessage( dlg, & msg ) ) {
      TranslateMessage( & msg );
      DispatchMessage( & msg );
    }
  }	
}

int main() {
  UserPassGetter upg;
  upg.Get();
  if ( upg.got ) {
    cout << "user: " << upg.user << " password: " << upg.pwd << endl;
  }
}

