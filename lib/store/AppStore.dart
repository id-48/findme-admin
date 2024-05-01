import 'package:mobx/mobx.dart';

import '../utils/Constants.dart';
import '../utils/Extensions/shared_pref.dart';

part 'AppStore.g.dart';

class AppStore = _AppStore with _$AppStore;

abstract class _AppStore with Store {
  @observable
  bool isLoggedIn = true;

  @observable
  bool isAdminLoggedIn = false;

  @observable
  bool isLoading = false;

  @observable
  int selectedMenuIndex = 0;

  @observable
  bool isMenuExpanded = true;

  @action
  Future<void> setLoggedIn(bool val, {bool isInitializing = false}) async {
    isLoggedIn = val;
    if (!isInitializing) await setValue(IS_LOGGED_IN, val);
  }

  @action
  Future<void> setAdminLoggedIn(bool val, {bool isInitializing = false}) async {
    isAdminLoggedIn = val;
    if (!isInitializing) await setValue(IS_ADMIN_LOGGED_IN, val);
  }

  @action
  Future<void> setLoading(bool value) async {
    isLoading = value;
  }

  @action
  void setSelectedMenuIndex(int val) {
    selectedMenuIndex = val;
  }

  @action
  void setExpandedMenu(bool val) {
    isMenuExpanded = val;
  }
}
