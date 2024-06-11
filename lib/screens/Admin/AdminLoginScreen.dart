import 'package:find_me_admin/screens/Admin/register_admin_screen.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/models/models.dart';
import 'package:find_me_admin/screens/Admin/get_users_screen.dart';
import 'package:find_me_admin/screens/Admin/get_billing_screen.dart';
import 'package:find_me_admin/utils/DataProvider.dart';
import 'package:find_me_admin/utils/Extensions/toast.dart';
import 'package:find_me_admin/utils/Images.dart';

import '../../components/AddButtonComponent.dart';
import '../../components/Admin/add_admin_dialog.dart';
import '../../main.dart';
import '../../models/user_model/res_login_user.dart';
import '../../network/RestApis.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Constants.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/remote_config.dart';
import '../../utils/Extensions/shared_pref.dart';
import '../../utils/Extensions/text_styles.dart';
import '../../utils/ResponsiveWidget.dart';

class AdminLoginScreen extends StatefulWidget {
  static String route = '/admin/login';

  @override
  AdminLoginScreenState createState() => AdminLoginScreenState();
}

class AdminLoginScreenState extends State<AdminLoginScreen> {
  final GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  TextEditingController emailController = TextEditingController();
  TextEditingController passwordController = TextEditingController();

  @override
  void initState() {
    super.initState();
    // init();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Row(
        children: [
          if (!ResponsiveWidget.isSmallScreen(context))
            Expanded(
              child: Container(
                color: primaryColor,
                child: Stack(
                  children: [
                    Align(
                      alignment: AlignmentDirectional.center,
                      child: Column(
                        mainAxisSize: MainAxisSize.min,
                        children: [
                          // Container(
                          //   child: Image.asset(app_logo_white),
                          //   height: 330,
                          //   width: 500,
                          // ),
                          SizedBox(height: 30),
                          Text(mAppName, style: boldTextStyle(color: Colors.white, size: 20)),
                        ],
                      ),
                    ),
                  ],
                ),
              ),
            ),
          Expanded(
            child: Container(
              padding: EdgeInsets.only(left: 50, right: 50, top: 50, bottom: 16),
              child: Stack(
                alignment: AlignmentDirectional.center,
                children: [
                  SingleChildScrollView(
                    child: Form(
                      key: _formKey,
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        mainAxisSize: MainAxisSize.min,
                        children: [
                          Text("Sign in", style: boldTextStyle(size: 30)),
                          SizedBox(height: 16),
                          Text("Sign in your account", style: secondaryTextStyle(size: 16)),
                          SizedBox(height: 50),
                          Text("Enter email Id", style: primaryTextStyle()),
                          SizedBox(height: 8),
                          AppTextField(
                            controller: emailController,
                            textFieldType: TextFieldType.EMAIL,
                            decoration: commonInputDecoration(),
                            textInputAction: TextInputAction.next,
                          ),
                          SizedBox(height: 16),
                          Text("Password", style: primaryTextStyle()),
                          SizedBox(height: 8),
                          AppTextField(
                            controller: passwordController,
                            textFieldType: TextFieldType.PASSWORD,
                            decoration: commonInputDecoration(),
                          ),
                          SizedBox(height: 30),
                          // InkWell(
                          //   onTap: () {
                          //     showDialog(
                          //       context: context,
                          //       barrierDismissible: false,
                          //       builder: (BuildContext dialogContext) {
                          //         return AddAdminDialog(
                          //           screen: 'login',
                          //         );
                          //       },
                          //     );
                          //   },
                          //   child: Text('Register Admin!',
                          //       style: primaryTextStyle(color: primaryColor, decoration: TextDecoration.underline)),
                          // ),
                          Align(
                            alignment: Alignment.centerRight,
                            child: commonButton("Login", () async {
                              String emailVal = emailController.text.trim();
                              String passVal = passwordController.text.trim();

                              if (emailVal.isNotEmpty) {
                                if (passVal.isNotEmpty) {
                                  appStore.setLoading(true);
                                  var req = {'email': emailVal, 'password': passVal};
                                  ResLoginUser resLoginUser = await loginAdminUser(req: req);
                                  if (resLoginUser.status) {
                                    if(resLoginUser.token!=null){
                                      if (resLoginUser.token!.isNotEmpty) {
                                        setStringAsync('TOKEN', resLoginUser.token!);
                                        print('resLoginUser.token :::${resLoginUser.token}');
                                        await appStore.setLoggedIn(true);
                                        await appStore.setAdminLoggedIn(true);
                                        ToastUtils.showCustomToast(context, "Login successful", "success");
                                        appStore.setLoading(false);
                                        setString("userLogin", "admin");
                                        setString("showroomId", "admin");
                                        Navigator.pushNamed(context, GetUsersScreen.route);
                                      }
                                    }

                                  } else {
                                    appStore.setLoading(false);
                                    ToastUtils.showCustomToast(context, resLoginUser.reason, "warning");
                                  }
                                  // if (GetAuthCredential().email == emailVal &&
                                  //     GetAuthCredential().password == passVal) {
                                  //   await appStore.setLoggedIn(true);
                                  //   await appStore.setAdminLoggedIn(true);
                                  //   ToastUtils.showCustomToast(context, "Login successful", "success");
                                  //   appStore.setLoading(false);
                                  //   setString("userLogin", "admin");
                                  //   setString("showroomId", "admin");
                                  //   Navigator.pushNamed(context, GetUsersScreen.route);
                                  // } else {
                                  //   ToastUtils.showCustomToast(
                                  //       context, "Please enter valid email and password!", "warning");
                                  // }
                                } else {
                                  ToastUtils.showCustomToast(context, "Please enter Password.", "warning");
                                }
                              } else {
                                ToastUtils.showCustomToast(context, "Please enter empId.", "warning");
                              }
                            }, width: 200),
                          ),
                        ],
                      ),
                    ),
                  ),
                  Observer(builder: (context) => appStore.isLoading ? loaderWidget() : SizedBox()),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}
